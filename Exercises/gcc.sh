mkdir GCC
for i in 01 02 03 04 05 06 07 08 09
do
	for f in Chapter\ $i/*; do filename=$(basename "$f"); filename="${filename%.*}"; echo ${filename}; g++ -std=c++17 "$f" -o GCC/${filename}; done
done
for i in 10 11 12 13 14 15 16 17 18 19
do
	for d in Chapter\ $i/*; do filename=$(basename "$d"); cd "$d"; echo ${filename}; g++ -std=c++17 * -o ../../GCC/${filename}; cd ../..; done
done
