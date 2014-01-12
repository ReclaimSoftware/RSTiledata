mkdir -p build

$CC \
        -std=c99 \
        -isystem ./ \
        -c RSTiledata.c \
        -o build/RSTiledata.o &&
    echo 'Built.'
