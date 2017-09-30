reset
set ylabel 'time(sec)'
set style fill solid
set title 'performance comparison'
set term png enhanced font 'Times_New_Roman,10'
set output 'runtime.png'

plot [:][:0.05]'output.txt' using 2:xtic(1) with histogram title 'original' linecolor rgb "#D46A6A", \
'' using ($0-0.06):($2+0.001):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'optimized' linecolor rgb "#4F618F" , \
'' using ($0+0.3):($3+0.0015):3 with labels title ' '
