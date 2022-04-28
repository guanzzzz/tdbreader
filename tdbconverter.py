import sys
from Configuration import type_transfer_namespace_ghser, type_transfer_namespace_sys, type_transfer_namespace_TDB
from Database import Database
from PyQt5 import QtCore, QtGui, QtWidgets

options = QtWidgets.QFileDialog.Options()
options |= QtWidgets.QFileDialog.DontUseNativeDialog


class Ui_tdbconverter(object):
    def setupUi(self, tdbconverter):
        tdbconverter.setObjectName("tdbconverter")
        tdbconverter.resize(500, 80)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(tdbconverter.sizePolicy().hasHeightForWidth())
        tdbconverter.setSizePolicy(sizePolicy)
        tdbconverter.setMinimumSize(QtCore.QSize(500, 80))
        tdbconverter.setMaximumSize(QtCore.QSize(500, 80))
        self.verticalLayout = QtWidgets.QVBoxLayout(tdbconverter)
        self.verticalLayout.setObjectName("verticalLayout")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.load_file_btn = QtWidgets.QToolButton(tdbconverter)
        self.load_file_btn.setMinimumSize(QtCore.QSize(60, 0))
        font = QtGui.QFont()
        font.setFamily("Arial")
        self.load_file_btn.setFont(font)
        self.load_file_btn.setObjectName("load_file_btn")
        self.gridLayout.addWidget(self.load_file_btn, 0, 2, 1, 1)
        self.loadfile_pos = QtWidgets.QLineEdit(tdbconverter)
        font = QtGui.QFont()
        font.setFamily("Arial")
        self.loadfile_pos.setFont(font)
        self.loadfile_pos.setObjectName("loadfile_pos")
        self.gridLayout.addWidget(self.loadfile_pos, 0, 1, 1, 1)
        self.label = QtWidgets.QLabel(tdbconverter)
        font = QtGui.QFont()
        font.setFamily("Arial")
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 0, 0, 1, 1)
        self.verticalLayout.addLayout(self.gridLayout)
        self.convert_btn = QtWidgets.QPushButton(tdbconverter)
        font = QtGui.QFont()
        font.setFamily("Arial")
        self.convert_btn.setFont(font)
        self.convert_btn.setObjectName("convert_btn")
        self.verticalLayout.addWidget(self.convert_btn)
        self.retranslateUi(tdbconverter)
        QtCore.QMetaObject.connectSlotsByName(tdbconverter)

    def retranslateUi(self, tdbconverter):
        _translate = QtCore.QCoreApplication.translate
        tdbconverter.setWindowTitle(_translate("tdbconverter", "tdbconverter"))
        self.load_file_btn.setText(_translate("tdbconverter", "..."))
        self.label.setText(_translate("tdbconverter", "Load File"))
        self.convert_btn.setText(_translate("tdbconverter", "Convert"))


class Converter(QtWidgets.QWidget, Ui_tdbconverter):
    def __init__(self):
        super(Converter, self).__init__()
        self.setupUi(self)

    @QtCore.pyqtSlot()
    def on_load_file_btn_clicked(self):
        file_dialog = QtWidgets.QFileDialog()
        database_file, _ = QtWidgets.QFileDialog.getOpenFileName(
            file_dialog, "Database", "", "TDB Files (*.tdb);;TDB Files (*.txt)", options=options)
        self.loadfile_pos.setText(database_file)

    @QtCore.pyqtSlot()
    def on_convert_btn_clicked(self):
        try:
            with open(self.loadfile_pos.text(), encoding='utf-8') as tdb:
                tdb_file = Database(tdb)
                tdb_file.configuration()
                namespace_ghser_x = type_transfer_namespace_ghser(tdb_file.FUNCTIONS)
                namespace_sys_y = type_transfer_namespace_sys(
                    tdb_file.ELEMENTS, tdb_file.PHASES, tdb_file.FUNCTIONS,
                    tdb_file.CONSTITUENTS, tdb_file.PARAMETERS)
                namespace_tdb = type_transfer_namespace_TDB(namespace_ghser_x, namespace_sys_y)
            file_dialog = QtWidgets.QFileDialog()
            database_file, _ = QtWidgets.QFileDialog.getSaveFileName(
                file_dialog, "Database", "", "C++ Header Files (*.h)", options=options)
            if database_file:
                if '.h' not in database_file:
                    database_file += '.h'
                with open(database_file, mode='w+') as h:
                    h.write(namespace_tdb)
                    messagebox = QtWidgets.QMessageBox()
                    QtWidgets.QMessageBox.question(messagebox, 'Message', 'Convert Complete',
                                                   QtWidgets.QMessageBox.Yes)
                self.close()
        except Exception as e:
            messagebox = QtWidgets.QMessageBox()
            QtWidgets.QMessageBox.question(messagebox, 'Warning', str(e), QtWidgets.QMessageBox.Yes)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    win = Converter()
    win.show()
    sys.exit(app.exec_())
