for NODES in 1000 3000 5000
do
    for DENSITY in 10 20 30 40 50 60 70 80 90 100
    do
        ./mst.out -r ${NODES} ${DENSITY}>>timefile.txt
        echo "\n"
    done
done
