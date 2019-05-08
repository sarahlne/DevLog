import os
os.environ["CC"] = "c++"
from distutils.core import setup, Extension
#Binary Symbolic Regression
module = Extension('BinSymReg', ["Solve.cpp","MyWrapper.cpp","Et.cpp","Fonction.cpp","Noeud.cpp","Non.cpp","Ou.cpp","Valeur.cpp","Variable.cpp"],include_dirs=[],libraries=[])
#importer la librairie 
module.extra_compile_args = []#,'-pg']

setup(name='BinSymReg',
	  version='1.0',
	  author='Poquillon Dandou Mikec Bonnal',
	  author_email='aurore.bonnal-conduzorgues@insa-lyon.fr',
	  ext_modules=[module])
