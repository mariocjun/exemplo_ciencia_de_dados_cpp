# create an variable for the path to gnuplot
$gnuplot = "C:\Program Files\gnuplot\bin\gnuplot.exe"

# create a variable for the path to the gnuplot script
$script = ".\plotting_Cpp11.gnuplot"

# ps1 script to load gnuplot
#& 'C:\Program Files\gnuplot\bin\gnuplot.exe' > load .\plotting_Cpp11.gnuplot
#Remove-Item .\load

& $gnuplot > load $script
Remove-Item .\load