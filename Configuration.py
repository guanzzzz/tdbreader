from Database import Database, transform_function


def type_transfer_namespace_ghser(function_of_database):
    FUNCTION_OF_DATABASE = function_of_database
    if isinstance(FUNCTION_OF_DATABASE, dict):
        namespace_ghser = \
            '       namespace ghser (\n' \
            '{STATIC_DOUBLE}' \
            '       )\n'
        pre_define_function = list(FUNCTION_OF_DATABASE.keys())
        static_doubles = ''

        for key in pre_define_function:
            range_list = FUNCTION_OF_DATABASE[key].range
            # print(range_list)
            transformed_expression_list = transform_function(FUNCTION_OF_DATABASE[key].expression, pre_define_function)
            static_double = \
                '               static double {FUNCTION_NAME} [double T] (\n' \
                '                       double val = 0.0;\n' \
                '{EXPRESSION}' \
                '                       return val;\n' \
                '               )\n'
            expression = \
                '                       if [T < {T_EXTRA_MIN} || T > {T_EXTRA_MAX}] (\n' \
                '                               printerror[];\n' \
                '                       )\n' \
                '{PIECEWISE_EXPRESSION}'
            piecewise_expressions = ''

            for i in range(len(transformed_expression_list)):
                piecewise_expression = \
                    '                       else if [T >= {T_MIN} && T {OPERATOR} {T_MAX}] (\n' \
                    '                               val = {TRANSFORMED_PIECE_EXPRESSION}\n' \
                    '                       )\n'

                if i < len(transformed_expression_list) - 1:
                    OPERATOR = '<'

                else:
                    OPERATOR = '<='

                piecewise_expressions += piecewise_expression.format(
                    T_MIN=range_list[i], OPERATOR=OPERATOR,
                    T_MAX=range_list[i + 1], TRANSFORMED_PIECE_EXPRESSION=transformed_expression_list[i])

            expression = expression.format(T_EXTRA_MIN=range_list[0], T_EXTRA_MAX=range_list[-1],
                                           PIECEWISE_EXPRESSION=piecewise_expressions)

            static_doubles += static_double.format(FUNCTION_NAME=key, EXPRESSION=expression)
        namespace_ghser_transformed = namespace_ghser.format(STATIC_DOUBLE=static_doubles)
        namespace_ghser_transformed = namespace_ghser_transformed.replace('(', '{').replace(')', '}')
        namespace_ghser_transformed = namespace_ghser_transformed.replace('[', '(').replace(']', ')').strip('}').strip()
        return namespace_ghser_transformed


def type_transfer_namespace_sys(elements_of_database, phase_of_database, function_of_database,
                                constituent_of_database, parameters_of_database, type_switch=True):
    ELEMENTS_OF_DATABASE = elements_of_database
    PHASE_OF_DATABASE = phase_of_database
    FUNCTION_OF_DATABASE = function_of_database
    CONSTITUENTS_OF_DATABASE = constituent_of_database
    PARAMETERS_OF_DATABASE = parameters_of_database
    TYPE_SWITCH = type_switch
    namespace_sys = \
        'namespace SYS{GLOBAL_CONSTITUENTS} @^@\n' \
        '               enum SUBLATTICES {SUBLATTICES};' \
        '\n               {STATIC_DOUBLES}' \
        '       ^@^'
    all_element_list = [i.upper() for i in list(ELEMENTS_OF_DATABASE.keys())]
    if '/-' in all_element_list:
        all_element_list.remove('/-')
    if 'VA' in all_element_list:
        all_element_list.remove('VA')
    global_constituent = ''
    for i in range(len(all_element_list)):
        global_constituent += '_'
        global_constituent += all_element_list[i]
    all_sublattice_list = []
    constituent_key_list = list(CONSTITUENTS_OF_DATABASE.keys())
    for i in range(len(constituent_key_list)):
        sub_constituent_list = CONSTITUENTS_OF_DATABASE[constituent_key_list[i]].sublattice
        for j in range(len(sub_constituent_list)):
            all_sublattice_list.append('_' + CONSTITUENTS_OF_DATABASE[constituent_key_list[i]].sublattice[j]
                                       .upper().replace(',', '_') + '_')
    all_sublattice_list = list(set(all_sublattice_list))
    sublattices = ''
    for i in range(len(all_sublattice_list)):
        sublattices += ' '
        sublattices += all_sublattice_list[i]
        sublattices += ','
    sublattices = sublattices.strip(',')
    pre_define_function = list(FUNCTION_OF_DATABASE.keys())
    if isinstance(PHASE_OF_DATABASE, dict):
        phases = list(PHASE_OF_DATABASE.keys())
        static_doubles = ''
        for i in range(len(phases)):
            sub_phase_list = PARAMETERS_OF_DATABASE[phases[i]]
            function_name_subphases = []
            pre_define_function_transformed = []
            for number in range(len(pre_define_function)):
                pre_define_function_transformed.append('ghser::' + pre_define_function[number])
            separator = \
                '               /**********************************************************************\n' \
                '               {DEFINITION_BELOW_NAME}\n' \
                '               **********************************************************************/\n'
            static_doubles += '\n'
            static_doubles += separator.format(DEFINITION_BELOW_NAME='PHASE {PHASE_NAME}'.format(PHASE_NAME=phases[i]))
            function_name_constituents_subconstituents = []
            subphase_subparameter_constituents = []
            for key in sub_phase_list:
                range_list = key[2].range
                subphase_subparameter_constituents.append(key[2].source_constituents)
                transformed_expression_list = transform_function(key[2].expression, pre_define_function)
                for j in range(len(transformed_expression_list)):
                    for k in range(len(pre_define_function)):
                        if pre_define_function[k] in transformed_expression_list[j]:
                            transformed_expression_list[j] = \
                                transformed_expression_list[j].replace(pre_define_function[k],
                                                                       pre_define_function_transformed[k] + '[T]')
                        if '#' in transformed_expression_list[j]:
                            transformed_expression_list[j] = transformed_expression_list[j].strip('#')
                static_double_subphase = \
                    '               static double {FUNCTION_NAME} $^$double T^$^ #^#\n' \
                    '                       double val = 0.0;\n' \
                    '{EXPRESSION}' \
                    '                       return val;\n' \
                    '               ^#^\n'
                expression_subphase = \
                    '                       if [T < {T_EXTRA_MIN} || T > {T_EXTRA_MAX}] (\n' \
                    '                               printerror[];\n' \
                    '                       )\n' \
                    '{PIECEWISE_EXPRESSION}'
                piecewise_expressions_subphase = ''
                for j in range(len(transformed_expression_list)):
                    piecewise_expression_subphase = \
                        '                       else if [T >= {T_MIN} && T {OPERATOR} {T_MAX}] (\n' \
                        '                               val = {TRANSFORMED_PIECE_EXPRESSION}\n' \
                        '                       )\n'
                    if j < len(transformed_expression_list) - 1:
                        OPERATOR = '<'
                    else:
                        OPERATOR = '<='
                    piecewise_expressions_subphase += piecewise_expression_subphase.format(
                        T_MIN=range_list[j], OPERATOR=OPERATOR,
                        T_MAX=range_list[j + 1],
                        TRANSFORMED_PIECE_EXPRESSION=transformed_expression_list[j]
                    )
                expression_subphase = expression_subphase.format(
                    T_EXTRA_MIN=range_list[0],
                    T_EXTRA_MAX=range_list[-1],
                    PIECEWISE_EXPRESSION=piecewise_expressions_subphase
                ).replace('(', '{').replace(')', '}').replace('[', '(').replace(']', ')')
                function_name_constituents = key[2].source_constituents
                function_name_constituents_transfromed = ''
                for j in function_name_constituents:
                    function_name_constituents_transfromed += j.replace(',', '_')
                    function_name_constituents_transfromed += '_'
                function_name_subphase =\
                    key[2].type + '_' + str(key[2].source_phase_name) + '_' + function_name_constituents_transfromed\
                    + str(key[2].order)
                function_name_constituents_subconstituents.append(function_name_constituents)
                function_name_subphases.append(function_name_subphase)
                static_doubles += static_double_subphase.format(
                    FUNCTION_NAME=function_name_subphase,
                    EXPRESSION=expression_subphase).replace('#^#', '{').replace('^#^', '}'). \
                    replace('$^$', '(').replace('^$^', ')')
            separator = \
                '               //---------------------------------------------------------------------\n' \
                '               //{DEFINITION_BELOW_NAME}\n' \
                '               //---------------------------------------------------------------------\n'
            static_doubles += separator.format(DEFINITION_BELOW_NAME='Gibbs Energy')
            subphase_name = phases[i]
            subphase_proportion = PHASE_OF_DATABASE[phases[i]].proportion
            subphase_sublattice = CONSTITUENTS_OF_DATABASE[phases[i]].sublattice
            subphase_gibbs_energy_name = 'G' + '_' + subphase_name
            subphase_sublattce_subsublattice = []
            for j in subphase_sublattice:
                subphase_sublattce_subsublattice_constitution = list(j.split(','))
                subphase_sublattce_subsublattice.append(subphase_sublattce_subsublattice_constitution)
            for sublist in subphase_sublattce_subsublattice:
                if 'VA' in sublist:
                    sublist.remove('VA')
                if not sublist:
                    subphase_sublattce_subsublattice.remove([])
            transfromed_subphase_sublattice = []
            for j in subphase_sublattice:
                transformed_i = []
                transformed_j = j.replace(',', '_')
                transformed_i.append('_' + transformed_j + '_')
                transfromed_subphase_sublattice.append(transformed_i)
            transfromed_function_name_constituents_subconstituents = []
            for j in function_name_constituents_subconstituents:
                transformed_i = []
                for k in j:
                    transformed_j = k.replace(',', '_')
                    transformed_i.append('_' + transformed_j + '_')
                transfromed_function_name_constituents_subconstituents.append(transformed_i)
            static_double_gibbs = \
                '               static double {GIBBS_FUNCTION_NAME}(pf::SublatticeNode& {ORDER}, double T, double P)' \
                ' <\n' \
                '{GIBBS_DOUBLES}\n' \
                '                       return val;\n' \
                '               >'
            if len(subphase_sublattce_subsublattice) == 1:
                static_double_gibbs_x = \
                    '               static double {GIBBS_FUNCTION_NAME}(pf::ConNode& {ORDER}, double T, double P)' \
                    ' <\n' \
                    '{GIBBS_DOUBLES}\n' \
                    '                       return val;\n' \
                    '               >'
                site_doubles = ''
                site_double = \
                    '                       double {SITE_NAME} = x[{SOURCE_SUBLATTICE}].value;\n'
                site_double_names = []
                site_double_names_x = []
                for j in range(len(subphase_sublattce_subsublattice[0])):
                    if TYPE_SWITCH:
                        site_double_names_x.append('x' + subphase_sublattce_subsublattice[0][j].strip('%'))
                        site_double_names.append(subphase_sublattce_subsublattice[0][j].strip('%'))
                    else:
                        site_double_names_x.append('x' + subphase_sublattce_subsublattice[0][j])
                        site_double_names.append(subphase_sublattce_subsublattice[0][j])
                    site_doubles += site_double.format(SITE_NAME=site_double_names_x[j],
                                                       SOURCE_SUBLATTICE=site_double_names[j])
                val_doubles = \
                    '                       double val = {VAL_EXPRESSION}'
                val_expression = ''
                subval_subval = []
                if 'VA' in function_name_subphases:
                    function_name_subphases.remove('VA')
                order_list = []
                for j in range(len(function_name_subphases)):
                    subval = function_name_subphases[j] + '(T)'
                    subval_sublist = function_name_subphases[j].split('_')
                    subval_type = subval_sublist[0]
                    phase_name = subval_sublist[1]
                    order = subval_sublist[-1]
                    subval_sublist.remove(subval_type)
                    subval_sublist.remove(phase_name)
                    subval_sublist.remove(order)
                    if 'VA' in subval_sublist:
                        subval_sublist.remove('VA')
                    subval_sublist_val = []
                    for k in subval_sublist:
                        if k in site_double_names:
                            subval_sublist_val.append(k)
                    order_list.append(order)
                    if len(subval_sublist_val) == 1:
                        subval += '*'
                        for m in subval_sublist_val:
                            subval += 'x'
                            subval += m
                            subval += '*'
                        subval = subval.strip('*')
                        val_expression += subval
                        val_expression += '+'
                    else:
                        if int(order) == 0:
                            subval += '*'
                            for m in subval_sublist_val:
                                subval += 'x'
                                subval += m
                                subval += '*'
                            subval = subval.strip('*')
                            val_expression += subval
                            val_expression += '+'
                        else:
                            for k in range(int(order)):
                                subval += '*'
                                subval += '('
                                for m in subval_sublist_val:
                                    subval += 'x'
                                    subval += m
                                    subval += '-'
                                subval = subval.strip('-')
                                subval += ')'
                                subval += '*'
                                for m in subval_sublist_val:
                                    subval += 'x'
                                    subval += m
                                    subval += '*'
                                subval = subval.strip('*')
                                val_expression += subval
                                val_expression += '+'
                    subval_subval.append(subval)
                val_expression_latter = 'R*T*({SITE_LATTER_EXPRESSION})'
                site_latter_expression = ''
                site_latter_expression_subexpression = []
                for j in site_double_names_x:
                    site_latter_expression += '{}*log({})+'.format(j, j)
                    site_latter_expression_subexpression.append('{}*log({})'.format(j, j))
                site_latter_expression = site_latter_expression.strip('+')
                site_expression = ''
                for j in subval_subval:
                    site_expression += j
                    site_expression += '+'
                site_expression += val_expression_latter.format(SITE_LATTER_EXPRESSION=site_latter_expression)
                site_expression = val_doubles.format(VAL_EXPRESSION=site_expression)
                static_double_gibbs_x = static_double_gibbs_x.format(
                    GIBBS_FUNCTION_NAME=subphase_gibbs_energy_name,
                    ORDER='x',
                    GIBBS_DOUBLES=site_doubles + site_expression)
                static_double_gibbs_x = static_double_gibbs_x.replace('<', '{').replace('>', '}')
                static_doubles += static_double_gibbs_x
                static_doubles += '\n'
                static_doubles += separator.format(DEFINITION_BELOW_NAME='A first order partial derivatives')
                subval_subval_first_order = []
                for o in site_double_names:
                    symbol_x = 'x' + o
                    symbol_log_x = 'log(x{})'.format(o)
                    subphase_first_dirivatives_name = 'd' + subphase_gibbs_energy_name + '_d' + '_' + o
                    for j in range(len(function_name_subphases)):
                        subval = function_name_subphases[j] + '(T)'
                        subval_sublist = function_name_subphases[j].split('_')
                        subval_type = subval_sublist[0]
                        phase_name = subval_sublist[1]
                        order = subval_sublist[-1]
                        subval_sublist.remove(subval_type)
                        subval_sublist.remove(phase_name)
                        subval_sublist.remove(order)
                        if 'VA' in subval_sublist:
                            subval_sublist.remove('VA')
                        subval_sublist_val = []
                        for k in subval_sublist:
                            if k in site_double_names:
                                subval_sublist_val.append(k)
                        if len(subval_sublist_val) == 1:
                            if o in subval_sublist_val:
                                subval += '*'
                                subval += str(1)
                                val_expression += subval
                                val_expression += '+'
                                subval_subval_first_order.append(subval)
                            else:
                                val_expression += ''
                                subval_subval_first_order.append('')
                        else:
                            if o in subval_sublist_val:
                                if int(order) == 0:
                                    subval += '*'
                                    for m in subval_sublist_val:
                                        subval += 'x'
                                        subval += m
                                        subval += '*'
                                    subval = subval.strip('*')
                                    val_expression += subval
                                    val_expression += '+'
                                else:
                                    for k in range(int(order) - 1):
                                        subval += '*'
                                        subval += '('
                                        for m in subval_sublist_val:
                                            if m == o:
                                                subval += str(order)
                                                subval += '*'
                                            subval += 'x'
                                            subval += m
                                            subval += '-'
                                        subval = subval.strip('-')
                                        subval += ')'
                                        subval += '*'
                                        for m in subval_sublist_val:
                                            subval += 'x'
                                            subval += m
                                            subval += '*'
                                        val_expression += subval
                                        val_expression += '+'
                                subval_subval_first_order.append(subval)
                            else:
                                val_expression += ''
                                subval_subval_first_order.append('')
                    val_expression = val_expression.strip('+')
                    val_expression_latter = 'R*T*({X_SITE_LATTER_EXPRESSION})'
                    site_latter_expression_first_order_derivatives = ''
                    site_latter_subexpression_first_order_derivatives = []
                    for k in range(len(site_latter_expression_subexpression)):
                        if '{}*{}'.format(symbol_x, symbol_log_x) in site_latter_expression_subexpression[k]:
                            site_latter_expression_first_order_derivatives += '1+{}'.format(symbol_log_x)
                            site_latter_subexpression_first_order_derivatives.append('1+{}'.format(symbol_log_x))
                            site_latter_expression_first_order_derivatives += '+'
                        else:
                            site_latter_expression_first_order_derivatives += ''.format(symbol_log_x)
                            site_latter_subexpression_first_order_derivatives.append('0')
                            site_latter_expression_first_order_derivatives += '+'
                    site_latter_expression_first_order_derivatives = \
                        site_latter_expression_first_order_derivatives.strip('+')
                    first_order_derivatives_val_expression = val_expression + '+' + val_expression_latter.format(
                        X_SITE_LATTER_EXPRESSION=site_latter_expression_first_order_derivatives)
                    site_double_first_order_derivatives_untransformed = \
                        '                       double val = {SITE_DOUBLE_FIRST_ORDER_DERIVATIVES_LATTER}'
                    site_double_first_order_derivatives_subtransformed = \
                        site_double_first_order_derivatives_untransformed.format(
                            SITE_DOUBLE_FIRST_ORDER_DERIVATIVES_LATTER=first_order_derivatives_val_expression.strip('+')
                        )
                    first_order_derivatives_double = \
                        '               static double {FIRST_ORDER_DERIVATIVES_NAMES}(pf::ConNode& x, ' \
                        'double T, double P) < \n' \
                        '{SITE_DOUBLES}' \
                        '{SITE_DOUBLE_LATTER_FIRST_ORDER_DERIVATIVES}\n' \
                        '                       return val;\n' \
                        '               > \n'
                    site_double_first_order_derivatives_transformed = first_order_derivatives_double.format(
                        FIRST_ORDER_DERIVATIVES_NAMES=subphase_first_dirivatives_name,
                        SITE_DOUBLES=site_doubles,
                        SITE_DOUBLE_LATTER_FIRST_ORDER_DERIVATIVES=site_double_first_order_derivatives_subtransformed
                    )
                    static_doubles += site_double_first_order_derivatives_transformed. \
                        replace('<', '{').replace('>', '}')
                static_doubles += separator.format(DEFINITION_BELOW_NAME='A Second order partial derivatives')
                site_double_second_order_names = []
                for j in range(len(subphase_sublattce_subsublattice)):
                    temp_site_double_names = []
                    for k in range(len(subphase_sublattce_subsublattice[j])):
                        temp_site_double_names.append(subphase_sublattce_subsublattice[j][k])
                    site_double_second_order_names.append(temp_site_double_names)
                site_double_second_order_names_transformed = []
                for j in range(len(site_double_second_order_names)):
                    for k in range(len(site_double_second_order_names[0])):
                        for m in range(len(site_double_second_order_names[0])):
                            site_double_second_order_names_transformed_subname = \
                                'd' + site_double_second_order_names[0][k]
                            site_double_second_order_names_transformed_subname += \
                                'd' + site_double_second_order_names[0][m]
                            site_double_second_order_names_transformed.append(
                                site_double_second_order_names_transformed_subname)
                second_order_derivatives_double = \
                    '               static double {SECOND_ORDER_DERIVATIVES_NAMES}(pf::ConNode& x, ' \
                    'double T, double P) < \n' \
                    '{SITE_DOUBLES}' \
                    '{SITE_DOUBLE_LATTER_SECOND_ORDER_DERIVATIVES}\n' \
                    '                       return val;\n' \
                    '               > \n'
                subphase_second_order_derivatives_name = 'd' + subphase_gibbs_energy_name + '_'
                second_order_derivatives_doubles = ''
                for j in range(len(site_double_second_order_names_transformed)):
                    second_order_derivatives_names =\
                        subphase_second_order_derivatives_name + site_double_second_order_names_transformed[j]
                    second_order_derivatives_doubles += second_order_derivatives_double.format(
                        SECOND_ORDER_DERIVATIVES_NAMES=second_order_derivatives_names,
                        SITE_DOUBLES=site_doubles,
                        SITE_DOUBLE_LATTER_SECOND_ORDER_DERIVATIVES='                       double val = 0.0;'
                    )
                second_order_derivatives_doubles = second_order_derivatives_doubles.replace('<', '{').replace('>', '}')
                static_doubles += second_order_derivatives_doubles
            elif len(subphase_sublattce_subsublattice) == 2:
                site_doubles = ''
                site_double = \
                    '                       double {SITE_NAME} = y[{SOURCE_SUBLATTICE}][{OPPOSITE_COMPOSITION}].' \
                    'value;\n'
                site_double_names = []
                for j in range(len(subphase_sublattce_subsublattice)):
                    temp_site_double_names = []
                    for k in range(len(subphase_sublattce_subsublattice[j])):
                        temp_site_double_names.append(
                            'y' + '{num}'.format(num=j + 1) + subphase_sublattce_subsublattice[j][k])
                    site_double_names.append(temp_site_double_names)
                slot_group = []
                for j in range(len(site_double_names)):
                    for k in range(len(site_double_names[j])):
                        slot_subgroup = [site_double_names[j][k], transfromed_subphase_sublattice[j][0],
                                         subphase_sublattce_subsublattice[j][k]]
                        site_doubles += site_double.format(SITE_NAME=slot_subgroup[0],
                                                           SOURCE_SUBLATTICE=slot_subgroup[1],
                                                           OPPOSITE_COMPOSITION=slot_subgroup[2])
                        slot_group.append(slot_subgroup)
                transformed_subphase_subparameter_constituents = []
                for j in subphase_subparameter_constituents:
                    transformed_subphase_subparameter_subconstituents = []
                    for k in range(len(j)):
                        if ',' in j[k]:
                            j_list = j[k].split(',')
                            for m in j_list:
                                transformed_subphase_subparameter_subconstituents.append(
                                    'y{num}'.format(num=k + 1) + m)
                        else:
                            transformed_subphase_subparameter_subconstituents.append('y{num}'.format(num=k + 1) + j[k])
                    transformed_subphase_subparameter_constituents.append(
                        transformed_subphase_subparameter_subconstituents)
                val_doubles = \
                    '                       double val = {VAL_EXPRESSION}'
                val_expression = ''
                subval_subval = []
                for j in range(len(function_name_subphases)):
                    subval = function_name_subphases[j] + '(T)'
                    for k in transformed_subphase_subparameter_constituents[j]:
                        subval += '*'
                        subval += k
                    val_expression += subval
                    val_expression += '+'
                    subval_subval.append(subval)
                val_expression_latter = '{PROPORTION_X_SITE}*R*T*{X_SITE_LATTER_EXPRESSION}+' \
                                        '{PROPORTION_Y_SITE}*R*T*{Y_SITE_LATTER_EXPRESSION}'
                site_latter_expression = []
                for j in site_double_names:
                    if len(j) == 1:
                        site_latter_expression.append('{}*log({})'.format(j[0], j[0]))
                    else:
                        site_latter_subexpression = '({})'
                        site_latter_subexpression_subexpression = ''
                        for k in j:
                            site_latter_subexpression_subexpression += '{}*log({})+'.format(k, k)
                        site_latter_subexpression_subexpression = site_latter_subexpression_subexpression.strip('+')
                        site_latter_subexpression = \
                            site_latter_subexpression.format(site_latter_subexpression_subexpression)
                        site_latter_expression.append(site_latter_subexpression)
                sum_proportion = 0
                subphase_proportion_transformed = []
                for j in subphase_proportion:
                    sum_proportion += float(j)
                for j in subphase_proportion:
                    subphase_proportion_transformed.append(float(j) / sum_proportion)
                val_expression += val_expression_latter.format(PROPORTION_X_SITE=subphase_proportion_transformed[0],
                                                               X_SITE_LATTER_EXPRESSION=site_latter_expression[0],
                                                               PROPORTION_Y_SITE=subphase_proportion_transformed[1],
                                                               Y_SITE_LATTER_EXPRESSION=site_latter_expression[1])
                gibbs_doubles = ''
                gibbs_doubles += site_doubles
                gibbs_doubles += val_doubles.format(VAL_EXPRESSION=val_expression)
                gibbs_doubles_untransformed = static_double_gibbs.format(GIBBS_FUNCTION_NAME=subphase_gibbs_energy_name,
                                                                         ORDER='y',
                                                                         GIBBS_DOUBLES=gibbs_doubles)
                gibbs_doubles_transformed = gibbs_doubles_untransformed.replace('<', '{').replace('>', '}')
                static_doubles += gibbs_doubles_transformed
                static_doubles += '\n'
                static_doubles += separator.format(DEFINITION_BELOW_NAME='A first order partial derivatives')
                site_double_subnames = []
                for j in site_double_names:
                    for k in j:
                        site_double_subnames.append(k)
                site_double_first_order_derivatives_not_deleted = []
                for j in site_double_subnames:
                    site_double_first_order_derivatives = ''
                    subphase_first_dirivatives_name = 'd' + subphase_gibbs_energy_name + '_d'
                    site_double_subnames_number = list(filter(str.isdigit, j))
                    site_double_subnames_element = j.strip('y').strip(site_double_subnames_number[0])
                    subphase_first_dirivatives_name += site_double_subnames_element
                    subphase_first_dirivatives_name += site_double_subnames_number[0]
                    symbol_x = j
                    symbol_log_x = 'log({})'.format(j)
                    for k in subval_subval:
                        if symbol_x not in k:
                            pass
                        else:
                            site_double_first_order_derivatives_subexpression = ''
                            symbol_x_count = k.count(symbol_x)
                            subval_subval_subval = k.split('*')
                            extra_parameter_subval = []
                            subval_subval_subval_compare_list = [j for j in subval_subval_subval]
                            for m in range(len(subval_subval_subval)):
                                del_times = 0
                                extra_parameter = 1
                                if subval_subval_subval_compare_list[m] == symbol_x and del_times == 0:
                                    del_times += 1
                                    extra_parameter = symbol_x_count
                                    del subval_subval_subval[m]
                                if extra_parameter != 1:
                                    extra_parameter_subval.append(extra_parameter)
                            for m in subval_subval_subval:
                                site_double_first_order_derivatives_subexpression += m
                                site_double_first_order_derivatives_subexpression += '*'
                            if len(extra_parameter_subval) == 0:
                                site_double_first_order_derivatives_subexpression += str(1)
                            else:
                                site_double_first_order_derivatives_subexpression += str(extra_parameter_subval[0])
                            site_double_first_order_derivatives_subexpression += '+'
                            site_double_first_order_derivatives_not_deleted.append(
                                site_double_first_order_derivatives)
                            site_double_first_order_derivatives += site_double_first_order_derivatives_subexpression
                    site_latter_expression_first_order_derivatives = []
                    for k in range(len(site_latter_expression)):
                        if '{}*{}'.format(symbol_x, symbol_log_x) in site_latter_expression[k]:
                            site_latter_expression_first_order_derivatives.append('1+{}'.format(symbol_log_x))
                        else:
                            site_latter_expression_first_order_derivatives.append('0')
                    for k in site_latter_expression_first_order_derivatives:
                        site_double_first_order_derivatives += k
                        site_double_first_order_derivatives += '+'
                    x_site_latter_expression = '(' + site_latter_expression_first_order_derivatives[0] + ')'
                    y_site_latter_expression = '(' + site_latter_expression_first_order_derivatives[1] + ')'
                    site_double_first_order_derivatives += \
                        val_expression_latter.format(PROPORTION_X_SITE=subphase_proportion_transformed[0],
                                                     X_SITE_LATTER_EXPRESSION=x_site_latter_expression,
                                                     PROPORTION_Y_SITE=subphase_proportion_transformed[1],
                                                     Y_SITE_LATTER_EXPRESSION=y_site_latter_expression)
                    site_double_first_order_derivatives_untransformed = \
                        '                       double val = {SITE_DOUBLE_FIRST_ORDER_DERIVATIVES_LATTER}'
                    site_double_first_order_derivatives_htransformed = site_double_first_order_derivatives.strip('+')
                    first_order_derivatives_double = \
                        '               static double {FIRST_ORDER_DERIVATIVES_NAMES}(pf::SublatticeNode& y, ' \
                        'double T, double P) < \n' \
                        '{SITE_DOUBLES}' \
                        '{SITE_DOUBLE_LATTER_FIRST_ORDER_DERIVATIVES}\n' \
                        '                       return val;\n' \
                        '               > \n'
                    site_double_first_order_derivatives_transformed = \
                        site_double_first_order_derivatives_untransformed.format(
                            SITE_DOUBLE_FIRST_ORDER_DERIVATIVES_LATTER=site_double_first_order_derivatives_htransformed
                        )
                    first_order_derivatives_double_transformed = first_order_derivatives_double.format(
                        FIRST_ORDER_DERIVATIVES_NAMES=subphase_first_dirivatives_name,
                        SITE_DOUBLES=site_doubles,
                        SITE_DOUBLE_LATTER_FIRST_ORDER_DERIVATIVES=site_double_first_order_derivatives_transformed
                    )
                    static_doubles += first_order_derivatives_double_transformed. \
                        replace('<', '{').replace('>', '}')
                static_doubles += separator.format(DEFINITION_BELOW_NAME='A Second order partial derivatives')
                site_double_second_order_names = []
                for j in range(len(subphase_sublattce_subsublattice)):
                    temp_site_double_names = []
                    for k in range(len(subphase_sublattce_subsublattice[j])):
                        temp_site_double_names.append(subphase_sublattce_subsublattice[j][k])
                    site_double_second_order_names.append(temp_site_double_names)
                site_double_second_order_names_transformed = []
                for j in range(len(site_double_second_order_names)):
                    for k in range(len(site_double_second_order_names[0])):
                        for m in range(len(site_double_second_order_names[1])):
                            site_double_second_order_names_transformed_subname = \
                                'd' + site_double_second_order_names[0][k]
                            site_double_second_order_names_transformed_subname += \
                                'd' + site_double_second_order_names[1][m]
                            site_double_second_order_names_transformed.append(
                                site_double_second_order_names_transformed_subname)
                second_order_derivatives_double = \
                    '               static double {SECOND_ORDER_DERIVATIVES_NAMES}((pf::SublatticeNode& y, ' \
                    'double T, double P) < \n' \
                    '{SITE_DOUBLES}' \
                    '{SITE_DOUBLE_LATTER_SECOND_ORDER_DERIVATIVES}\n' \
                    '                       return val;\n' \
                    '               > \n'
                subphase_second_order_derivatives_name = 'd' + subphase_gibbs_energy_name + '_'
                second_order_derivatives_doubles = ''
                for j in range(len(site_double_second_order_names_transformed)):
                    second_order_derivatives_names =\
                        subphase_second_order_derivatives_name + site_double_second_order_names_transformed[j]
                    second_order_derivatives_doubles += second_order_derivatives_double.format(
                        SECOND_ORDER_DERIVATIVES_NAMES=second_order_derivatives_names,
                        SITE_DOUBLES=site_doubles,
                        SITE_DOUBLE_LATTER_SECOND_ORDER_DERIVATIVES='                       double val = 0.0;'
                    )
                second_order_derivatives_doubles = second_order_derivatives_doubles.replace('<', '{').replace('>', '}')
                static_doubles += second_order_derivatives_doubles
                # static_doubles += separator.format(DEFINITION_BELOW_NAME='D I F F U S I O N     D A T A')
            elif len(subphase_sublattce_subsublattice) == 3:
                definition_below_name = \
                    'PHASE {PHASE_NAME} with sublattice{SUBLATTICE}'.format(
                        PHASE_NAME=phases[i], SUBLATTICE=str(len(subphase_sublattce_subsublattice)))
                static_doubles += separator.format(
                    DEFINITION_BELOW_NAME=definition_below_name)
                static_doubles += '\n\n\n\n\n'
            else:
                definition_below_name = \
                    'PHASE {PHASE_NAME} with sublattice{SUBLATTICE}'.format(
                        PHASE_NAME=phases[i], SUBLATTICE=str(len(subphase_sublattce_subsublattice)))
                static_doubles += separator.format(
                    DEFINITION_BELOW_NAME=definition_below_name)
                static_doubles += '\n\n\n\n\n'
        namespace_sys = namespace_sys.format(GLOBAL_CONSTITUENTS=global_constituent, SUBLATTICES=sublattices,
                                             STATIC_DOUBLES=static_doubles)
        namespace_sys = namespace_sys.replace('@^@', '{').replace('^@^', '}')
        return namespace_sys
    else:
        return None


def type_transfer_namespace_TDB(namespace_ghser, namespace_sys):
    namespace_tdb_former = \
        'namespace TDB {\n' \
        '       using namespace pf::materials;\n' \
        '\n' \
        '       static void printerror(){\n' \
        '               cout << "Temperature, out of limit, thermodynamic calculation error!" << endl;\n' \
        '               SYS_PROGRAM_STOP;\n' \
        '       }\n' \
        '       static void printerror(double T) {\n' \
        '               cout << "Temperature, out of limit, thermodynamic calculation error!" << endl;\n' \
        '               SYS_PROGRAM_STOP;\n' \
        '       }\n' \
        '       const double R = 8.3144521;\n' \
        '\n'
    namespace_tdb_former_middle = \
        '       {NAMESPACE_GHSER}' \
        '\n' \
        '       {NAMESPACE_SYS}'
    namespace_tdb_former_latter = \
        '\n' \
        '}'
    return namespace_tdb_former + namespace_tdb_former_middle.format(
        NAMESPACE_GHSER=namespace_ghser,
        NAMESPACE_SYS=namespace_sys).replace('#', '') + namespace_tdb_former_latter


if __name__ == "__main__":
    with open("Sn-Ag-Bi.TDB", encoding='utf-8') as tdb:
        tdb_file = Database(tdb)
        tdb_file.configuration()
        namespace_ghser_x = type_transfer_namespace_ghser(tdb_file.FUNCTIONS)
        namespace_sys_y = type_transfer_namespace_sys(
            tdb_file.ELEMENTS, tdb_file.PHASES, tdb_file.FUNCTIONS, tdb_file.CONSTITUENTS, tdb_file.PARAMETERS)
        namespace_tdb = type_transfer_namespace_TDB(namespace_ghser_x, namespace_sys_y)
    with open('Sn-Ag-Bi.h', mode='w') as h:
        h.write(namespace_tdb)
        # print(namespace_tdb)
