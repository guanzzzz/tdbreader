import re


def transform_function(function_list, pre_define_function):
    transformed_pre_define_function = [i + '(T)' for i in pre_define_function]
    function_transformed_list = []
    for piecewise_function in function_list:
        transformed_piecewise_function = piecewise_function.replace('LN(T)', 'log(T)').replace('**', '*')
        args_to_replace_list = re.findall(r'[(](.*?)[)]', transformed_piecewise_function)
        t = []
        for i in range(len(args_to_replace_list)):
            t.append('(slot{})'.format(i))
            transformed_piecewise_function = transformed_piecewise_function.replace(
                "({})".format(args_to_replace_list[i]), t[i])
            if args_to_replace_list[i] == 'T':
                args_to_replace_list[i] = '(T)'
            else:
                args_to_replace_list[i] = 'pow(T,{})'.format(i)
        for i in range(len(t)):
            transformed_piecewise_function = transformed_piecewise_function.replace('{}'.format(t[i]),
                                                                                    args_to_replace_list[i])
        function_transformed_list.append(transformed_piecewise_function.replace('(', '[').replace(')', ']'))
        for i in range(len(pre_define_function)):
            if pre_define_function[i] in transformed_piecewise_function:
                transformed_piecewise_function = transformed_piecewise_function.replace(pre_define_function[i],
                                                                                        transformed_pre_define_function[
                                                                                            i])
    return function_transformed_list


class Database(object):
    """
    TDB Database Reader

    SPECIES: dict
        {species name: Species object.....}
    ELEMENTS: dict
        {element name: Element object.....}
    FUNCTIONS: dict
        {function name: Element object.....}
    PHASES: dict
        {phase name: Phase object.....}
    PARAMETERS: dict
        {parameter source phase name: [source constituents, order, Parameter object].....}
    CONSTITUENTS: dict
        {constituent name: Constituent object.....}
    TYPE_DEFINITION: dict
        {phase name: [data_type_code, Type_definition object].....}
    LIST_OF_REFERENCES: None or List_of_reference object

    Method
        Database.configuration(record_object=None): configure the tdb file by lines
            optional parameter: record_object
                record_object: reading result as a dict
        Database.show_read_results(): return reading result as a dict
            dict type:
                {Line id: Content.....}
        Database.show_note(): return reading note result as a dict
            dict type:
                {Line id: Content.....}
    """
    SPECIES = {}
    ELEMENTS = {}
    FUNCTIONS = {}
    PHASES = {}
    PARAMETERS = {}
    CONSTITUENTS = {}
    TYPE_DEFINITION = {}
    LIST_OF_REFERENCES = None

    class Species:
        """
        Species definition in TDB

        Example in TDB:
            Species AL2O3 AL2O3 !

        Explanation according to the order of definition:
            Species: Keyword of the beginning definition of an Species
            AL2O3: Species name
            AL2O3: Definition
            '!': Keyword of end definition

        Class Species:
            Species name: self.species_name
            Definition: self.species_definition
            '!': Keyword of end definition
        """

        def __init__(self, args):
            self.species_name = args[1]
            self.species_definition = ''
            for i in range(len(args) - 2):
                if '!' == args[i + 2]:
                    pass
                elif '!' in args[i + 2]:
                    self.species_definition = args[i + 2].strip('!')
                else:
                    self.species_definition = args[i + 2]

    class Element:
        """
        Element definition

        Example in TDB:
            Element Zn HCP_A3 65.39 5656.7 41.631 !

        Explanation according to the order of definition:
            Element: Keyword of the beginning definition of an Element
            Zn: Element symbol
            HCP_A3: Reference structure
            65.39: Atomic weight (g/mol)
            5656.7: H298-H0
            41.631: S298
            '!': Keyword of end definition

        Class Element:
            Element symbol: self.element_name
            Reference structure: self.reference
            Atomic weight (g/mol): self.mass
            H298-H0: self.H298
            S298: self.S298
        """

        def __init__(self, args):
            self.element_name = args[1]
            self.reference = args[2]
            self.mass = args[3]
            self.H298 = args[4]
            self.S298 = args[5]

    class Function:
        """
        Parameter definition

        Example in TDB:
            Function GHSERAL 2.98140E+02
                 -7976.15+137.093038*T-24.3671976*T*LN(T)-.001884662*T**2-8.77664E-07*T**3+74092*T**(-1);
                   7.00000E+02  Y
                 -11276.24+223.048446*T-38.5844296*T*LN(T)+.018531982*T**2-5.764227E-06*T**3+74092*T**(-1);
                   9.33470E+02  Y
                 -11278.378+188.684153*T-31.748192*T*LN(T)-1.230524E+28*T**(-9);
                   2.90000E+03  N !

        Explanation according to the order of definition:
            Function: Keyword of the beginning definition of a Parameter of given phase and constituent
            GHSERAL: Function name
            2.98140E+02: Starting temperature
            -7976.15+137.093038*T-24.3671976*T*LN(T)-.001884662*T**2-8.77664E-07*T**3+74092*T**(-1):
                Piecewise expression
            ';': End of piecewise expression
            Y: Keyword of piecewise incomplete function
            7.00000E+02: Second starting temperature
            N: Keyword of end of function
            '!': Keyword of end definition

        Class Function:
            Function name: self.function_name
            Temperature range: self.range (List)
            Piecewise expression of the function: self.expression (List)
        """

        def __init__(self, args):
            self.function_name = args[1]
            self.range = []
            self.expression = []
            range_args = True
            temp_expression = ''
            for i in range(len(args) - 2):
                if range_args:
                    self.range.append(args[i + 2])
                    range_args = False
                elif args[i + 2][-1] == ';':
                    temp_expression += args[i + 2].strip(';')
                    self.expression.append(temp_expression)
                    range_args = True
                    temp_expression = ''
                elif args[i + 2][-1] == 'N' or args[i + 2][-1] == 'Y':
                    pass
                else:
                    temp_expression += args[i + 2]

    class Phase:
        """
        Phase definition

        Example in TDB:
            Phase BCC_A2 % & 2 1 3 !

        Explanation according to the order of definition:
            Phase: Keyword of the beginning definition of a phase
            BCC_A2: Phase name
            %: Separator
            &: Append phase description (optional)
            2: Number of sublattices
            1 3: Sublattices sizes
            !: Keyword of end definition

        Class Parameter:
            Phase: self.phase_name
            Append phase description: self.append_phase_description
            Number of sublattices: self.number_of_sublattices
            Sublattices sizes: self.proportion
        """

        def __init__(self, args):
            self.phase_name = args[1]
            self.separator = args[2]
            self.proportion = []
            self.append_phase_description = None
            if args[3].isdigit():
                self.number_of_sublattices = args[3]
                for i in range(len(args) - 4):
                    if args[i + 4] != '!':
                        self.proportion.append(args[i + 4])
            else:
                self.append_phase_description = args[3]
                self.number_of_sublattices = args[4]
                for i in range(len(args) - 5):
                    if args[i + 5] != '!':
                        self.proportion.append(args[i + 5])

    class Parameter:
        """
        Parameter definition

        Example in TDB:
            Parameter G(Liquid,Al,Mg,Zn,0) 298.15  -4094.48; 6000 N REF:0 !
            Parameter G(Liquid,Al,Mg,Zn,1) 298.15  -39973.7; 6000 N REF:0 !
            Parameter G(Liquid,Al,Mg,Zn,2) 298.15  -11337.5; 6000 N REF:0 !

        Explanation according to the order of definition:
            Parameter: Keyword of the beginning definition of a Parameter of given phase and constituent
            G: Type
            Liquid: Phase name
            Al,Mg,Zn: Constituents
            0/1/2: Power index of interaction
            298.15  -4094.48; 6000: Function
            N(or Y): End of function(or piecewise incomplete function)
            REF:0: Function reference
            '!': Keyword of end definition

        Class Parameter:
            Type: self.type
            Phase name: self.source_phase_name
            Constituents: self.source_constituents (List)
            Power index of interaction: self.order
            Temperature range: self.range (List)
            Piecewise expression of the function: self.expression (List)
        """

        def __init__(self, args):
            if args[1].split('(')[0] == 'G':
                split_arg_1_list = args[1].split(';')
                self.order = split_arg_1_list[1].strip(')')
                split_arg_1_former_list = split_arg_1_list[0].split(',')
                split_arg_1_former_former_list = split_arg_1_former_list[0].split('(')
                self.type = split_arg_1_former_former_list[0]
                self.source_phase_name = split_arg_1_former_former_list[1]
                temp_constituents = ''
                for i in range(len(split_arg_1_former_list) - 1):
                    temp_constituents += split_arg_1_former_list[i + 1] + ','
                split_constituents_list = temp_constituents.split(':')
                self.source_constituents = [i.strip(',') for i in split_constituents_list]
                self.range = []
                self.expression = []
                self.reference = ''
                range_args = True
                temp_expression = ''
                for i in range(len(args) - 2):
                    if range_args:
                        self.range.append(args[i + 2])
                        range_args = False
                    elif 'REF' in args[i + 2]:
                        self.reference = args[i + 2]
                    elif args[i + 2][-1] == ';':
                        temp_expression += args[i + 2].strip(';')
                        self.expression.append(temp_expression)
                        range_args = True
                        temp_expression = ''
                    elif args[i + 2][-1] == 'N' or args[i + 2][-1] == 'Y':
                        pass
                    else:
                        temp_expression += args[i + 2]
            elif args[1].split('(')[0] == 'MQ':
                split_arg_1_list = args[1].split('(')
                self.type = split_arg_1_list[0]

    class Constituent:
        """
        Constituent definition

        Example in TDB:
            Constituent BCC_A2: Al,Mg,Zn : Va : !

        Explanation according to the order of definition:
            Constituent: Keyword of the beginning definition of a constituent
            BCC_A2: Phase name
            ':': Separator
            Al,Mg,Zn: Constituent on sublattice
            !: Keyword of end definition

        Class Parameter:
            Phase name: self.constituent_name
            Constituent on sublattice: self.sublattice (List)
        """

        def __init__(self, args):
            self.constituent_name = args[1]
            self.sublattice = []
            while ':' in args:
                args.remove(':')
            for i in range(len(args) - 2):
                self.sublattice.append(args[i + 2].strip(':'))

    class Type_definition:
        """
        Type definition of a given phase

        Example in TDB:
            Type_Definition a GES A_P_D FCC_A1 Magnetic -3 0.28 !
            Type_Definition b GES A_P_D BCC_A2 DISORDER_PART BCC_A2 !
            TYPE_DEFINITION % SEQ * ! (Definition for Thermo-calc, ignored)

        Explanation according to the order of definition:
            Type_Definition: Keyword of the beginning definition of Type_Definition
            a/b: Data-type code
            GES: Keyword
            A_P_D: Append phase description
            FCC_A1/BCC_A2: Phase name
            Magnetic/DISORDER_PART: Special property
            -3: Antiferromagnetic factor: -1 for BCC; -3 for FCC and HCP
            0.28: The fraction of the magnetic enthalpy absorbed above the critical temperature,
                    depends on the structure
                    p = 0.40 for BCC
                    p = 0.28 for FCC, HCP...
            BCC_A2: Disordered part
            '!': Keyword of end definition

        Class Type_definition:
            Data-type code: self.data_type_code
            Keyword: self.keyword
            Append phase description: self.append_phase_description
            Phase name: self.phase_name
            Special property: self.property
            Antiferromagnetic factor: self.f
            P: self.p
        """

        def __init__(self, args):
            if args[1] == '%':
                self.data_type_code = args[1]
                self.phase_name = args[2]
                self.keyword = args[3]
                if '!' in self.keyword:
                    self.keyword.strip('!')
            elif args[1] == 'a' or '&':
                self.data_type_code = args[1]
                self.keyword = args[2]
                self.append_phase_description = args[3]
                # pprint(args)
                self.phase_name = args[4]
                self.property = args[5]
                self.f = args[6]
                if '!' in args[7]:
                    self.p = args[7].strip('!')
                else:
                    self.p = args[7]
            elif args[1] == 'b':
                self.data_type_code = args[1]
                self.keyword = args[2]
                self.append_phase_description = args[3]
                self.phase_name = args[4]
                self.property = args[5]
                if '!' in args[6]:
                    self.disordered_part = args[6].strip('!')
                else:
                    self.disordered_part = args[6]
            else:
                pass

    class List_of_reference:
        """
        List of reference

        Example in TDB:
             LIST_OF_REFERENCES
                 NUMBER  SOURCE
                 REF1  'Theoretical assessment of the Ni–Sn system,
                     Monatsh Chem (2012) 143:1255–1261 '
                 REF2  'The Thermodynamic Database for the Development of Modern
                     Lead-Free Solders,Defect and Diffusion Forum Vol 263 (2007) pp 99-104 '
                 REF3  'A thermodynamic assessment of Ni–Sb system,Computer Coupling
                     of Phase Diagrams and Thermochemistry,32 (2008) 378–388 '
                 REF4  'Phase equilibria in the ternary Ni–Sb–Sn system:
                     Experiments and calculations,CALPHAD: Computer Coupling of
                     Phase Diagrams and Thermochemistry,45 (2014) 151–166 '
             DATABASE-INFO 'FOR THE Sn-Ag-In DATABASE' !

        Explanation according to the order of definition:
            LIST_OF_REFERENCES: Keyword of the beginning definition of an reference
            NUMBER  SOURCE: Header
            REF1: Reference number
            'Theoretical assessment of the Ni–Sn system,
                     Monatsh Chem (2012) 143:1255–1261 ': Reference
            DATABASE-INFO: Keyword
            'FOR THE Sn-Ag-In DATABASE': Brief description of TDB documents
            '!': Keyword of end definition

        Class Element:
            Element symbol: self.element_name
            Reference structure: self.reference
            Atomic weight (g/mol): self.mass
            H298-H0: self.H298
            S298: self.S298
        """

        def __init__(self, args):
            self.ref_list = []
            self.ref_number = []
            rebuild_text = ''
            for i in range(len(args) - 3):
                rebuild_text += args[i + 3] + ' '
            rebuild_text_list = rebuild_text.strip('!').split("'")
            while ' ' in rebuild_text_list:
                rebuild_text_list.remove(' ')
            for i in range(len(rebuild_text_list)):
                if (i % 2) == 0:
                    self.ref_number.append(rebuild_text_list[i])
                else:
                    self.ref_list.append(rebuild_text_list[i])

    def __init__(self, tdb_file_to_open):
        self.name = tdb_file_to_open
        self.content = {}
        self.note = {}
        lines = self.name.read().splitlines()
        line_id = indicator_id = 1
        first_item = True
        for line in lines:
            if line.isspace():
                pass
            elif line == '':
                pass
            else:
                line = line.strip()
                if line[0] == '$' or line[0] == '#':
                    self.note[line_id] = line
                else:
                    if first_item:
                        if line[-1] == '!':
                            line = line.strip('!')
                            self.content[line_id] = line.split(' ')
                            indicator_id = line_id + 1
                        else:
                            self.content[line_id] = line.split(' ')
                            indicator_id = line_id
                        first_item = False
                    else:
                        if line[-1] != "!":
                            if indicator_id == line_id:
                                self.content[indicator_id] = line.split(' ')
                            else:
                                self.content[indicator_id] += line.split(' ')
                        else:
                            if indicator_id == line_id:
                                self.content[indicator_id] = line.strip('!').split(' ')
                            else:
                                self.content[indicator_id] += line.strip('!').split(' ')
                            indicator_id = line_id + 1
                line_id += 1

    def show_read_results(self):
        return self.content

    def show_note(self):
        return self.note

    def configuration(self, record_object=None):
        if record_object is None:
            for keys in self.content.keys():
                self.configuration_args(self.content[keys])
        elif isinstance(record_object, dict):
            for keys in record_object.keys():
                self.configuration_args(record_object[keys])
        else:
            pass

    def configuration_args(self, definition_args):
        while '' in definition_args:
            definition_args.remove('')
        if definition_args[0].upper() == 'ELEMENT' or definition_args[0].upper() == 'ELEM':
            self.ELEMENTS[self.Element(definition_args).element_name] = self.Element(definition_args)
        elif definition_args[0].upper() == 'FUNCTION':
            self.FUNCTIONS[self.Function(definition_args).function_name] = self.Function(definition_args)
        elif definition_args[0].upper() == 'PHASE':
            self.PHASES[self.Phase(definition_args).phase_name] = self.Phase(definition_args)
        elif definition_args[0].upper() == 'CONSTITUENT':
            self.CONSTITUENTS[self.Constituent(definition_args).constituent_name] = self.Constituent(definition_args)
        elif definition_args[0].upper() == 'PARAMETER':
            if self.Parameter(definition_args).source_phase_name in self.PARAMETERS:
                self.PARAMETERS[self.Parameter(definition_args).source_phase_name].append(
                    [self.Parameter(definition_args).source_constituents, self.Parameter(definition_args).order,
                     self.Parameter(definition_args)])
            else:
                self.PARAMETERS[self.Parameter(definition_args).source_phase_name] = \
                    [[self.Parameter(definition_args).source_constituents, self.Parameter(definition_args).order,
                      self.Parameter(definition_args)]]
        elif definition_args[0].upper() == 'SPECIES':
            self.SPECIES[self.Species(definition_args).species_name] = self.Species(definition_args)
        elif definition_args[0].upper() == 'TYPE_DEFINITION':
            self.TYPE_DEFINITION[self.Type_definition(definition_args).phase_name] = [
                self.Type_definition(definition_args).data_type_code, self.Type_definition(definition_args)]
        elif definition_args[0].upper() == 'LIST_OF_REFERENCES':
            self.LIST_OF_REFERENCES = self.List_of_reference(definition_args)


if __name__ == "__main__":
    tdb = open("Nb_La_Ga_ternary_gzh.tdb", encoding='utf-8')
    tdb_file = Database(tdb)
    tdb_file.configuration()
