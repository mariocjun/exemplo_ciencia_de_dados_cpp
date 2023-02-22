set key inside left top
set size ratio 9.0/16.0

set terminal pngcairo enhanced font "sans,12.0" size 700,700/16.0*9.0
set output 'fit_Cpp11.png'

plot 'fit_Cpp11.csv' using 1:2 with lines title 'Fit', 'anscombe.csv' using 1:2 with points pointtype 7 title 'Data'
