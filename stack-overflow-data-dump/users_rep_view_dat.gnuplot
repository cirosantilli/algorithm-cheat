#!/usr/bin/env gnuplot

set terminal png size 1024,1024
set output "users_rep_view.png"

#set terminal canvas enhanced mousing
#set termoption enhanced
#set output "users_rep_view.html"

#set terminal wxt size 1024,768
#set termoption enhanced

set logscale x
set logscale y
set key noautotitle
set xlabel "Reputation"
set ylabel "Profile Views"
plot "users_rep_view.dat" using 1:2
# TODO would allow interactive inspection with mouseover on HTML output, but makes graph generation too slow!
# https://stackoverflow.com/questions/13269811/how-to-show-a-label-from-a-third-data-column-on-mouseover-hover-in-a-gnuplot-s
#plot "users_rep_view.dat" using 1:2:3 with labels hypertext point pt 7
