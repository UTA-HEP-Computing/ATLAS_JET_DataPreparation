# ATLAS_JET_DataPreparation
The DataSet can be found here /eos/atlas/atlascerngroupdisk/perf-jets/JSS/TopBosonTagAnalysisRel21/FlattenerOutput/17Jan2019 in .root format
* **miniTreeMaker.cxx** used to make a smaller root file with required branch variables
* **rootTocsv.cxx** converts minitrees to txt file with required branch variables
* **fixed_length_creator.py** zero pad the txt files
`python fixed_length_creator.py input.txt output_zeropadded.txt`
* **txtToh5.py** converts zero padded output.txt to .h5 file
`python txtToh5.py output_zeropadded.txt`
