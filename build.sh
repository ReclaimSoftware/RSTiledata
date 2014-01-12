mkdir -p build

$CC \
        -std=c99 \
        -Wall \
        -isystem ./ \
        -c RSTiledata.c \
        -o build/RSTiledata.o &&
    echo 'Built.'
