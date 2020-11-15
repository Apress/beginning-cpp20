mkdir clang
for i in 01 02 03 04 05 06 07 08 09
do
	for f in Chapter\ $i/*; do filename=$(basename "$f"); filename="${filename%.*}"; echo ${filename}; clang++ -std=c++17 "$f" -o clang/${filename}; done
done
for i in 10 11 12 13 14 15 16 17 18 19
do
	for d in Chapter\ $i/*; do filename=$(basename "$d"); cd "$d"; echo ${filename}; clang++ -std=c++17 *.cpp -o ../../clang/${filename}; cd ../..; done
done
