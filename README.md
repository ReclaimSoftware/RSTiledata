## RSTiledata.h

```c
typedef enum {
    RSTiledataBuilding = 1,
    RSTiledataHighwayMotorway = 2,
    // [...]
    RSTiledataHighwayService = 7
} RSTiledataThingType;
```

## Datapack

A datapack is a LevelDB database with items of the form:

    key:    uint64le(zoom) + uint64le(x) + uint64le(y)
    value:  Tiledata

For disk locality, tiledata keys will probably later become `varint(zoom) + interleaved_uint64be_bits(x, y)`.


## Tiledata format

Given

- `zoom` (e.g. `17`)
- `tile_x`, `tile_y`
- `resolution_bits` (assumed to be 8 for now)

...we can decode this tiledata:

    *
      thing_type : varint
      num_nodes : varint
      +
        delta_x : signed varint
        delta_y : signed varint

...where `x` and `y` are quantized values in this space:

    (0, 0): this tile's upper-left corner
    (1, 1): this tile's lower-right corner

Before each tile, `x` and `y` are set to 0.

To convert `x` to the (zoom, x, y) space, divide by `(1 << resolution_bits)` and add `tile_x`.


### Example

To simplify the example, we assume `resolution_bits` is `2`.

Consider: one building (`X`s) and one tertiary highway (`\`s):

    \ 
    ----
    -XX-
    -X--
    ----  \

Tiledata:

    0106020204000002010000020100050200001E0A

More verbosely:

    01              building=*
    06              6 nodes             ------------------
      02 02          1  1    1  1       | Signed varints:
      04 00          3  1    2  0       |   0   00
      00 02          3  2    0  1       |   -1  01
      01 00          2  2   -1  0       |   1   02
      00 02          2  3    0  1       |   -2  03
      01 00          1  3   -1  0       |   2   04
                                        |   3   06
    05              highway=tertiary    |   4   08
    02              2 nodes             |   5   0A
      00 01          0 -1    0 -1       |   6   0C
      0E 0A          7  4    7  5       |   7   0E
