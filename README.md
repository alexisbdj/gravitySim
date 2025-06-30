# GravitySim

Simulates gravity using scaled distances for visualization and to manage float numbers precision, with [raylib](https://www.raylib.com/) for rendering from a fixed camera view.

The project currently works as intended, but here are some possible improvements:
- Add a 3D vector attribute type from scene description
- Describe scenes using JSON
- Simulate collisions
- Improve simulation accuracy to minimize long-term errors.

## Build

The project uses CMake and requires [raylib](https://www.raylib.com/) to be installed on your system.

### Linux example

```bash
mkdir build
cd build
cmake ..
make
./gravitySim ../examples/Ex01.tos
```

## Scene description

To write a scene descriptor, each object is defined as follows:
```
<object name> {
    <attribute> = <value>
}
```

Most values are of `float` type and are read using the `strtod` function.

### define camera

To define the camera, the object must have the special name `camera`.

| attribute | value  |
|-----------|--------|
| fovy      | float  |
| posX      | float  |
| posY      | float  |
| posZ      | float  |
| targetX   | float  |
| targetY   | float  |
| targetZ   | float  |
| up        | TODO   |

> the up attribute was not implemented. It should have the format `(+|-)(axis)`, ex : +y.
> Because it is not implemented, the up vector will always point to +y

The target vector will be used for a "lookat" camera

### define object

| attribute     | value  |
|---------------|--------|
| posX          | float  |
| posY          | float  |
| posZ          | float  |
| velocityX     | float  |
| velocityY     | float  |
| velocityZ     | float  |
| radius        | float  |
| mass          | float  |
| color         | string |
| circularOrbit | string |
| orbitDirX     | float  |
| orbitDirY     | float  |
| orbitDirZ     | float  |

the `color` attribute has a value from this list :
- BEIGE
- BLACK
- BLANK
- BLUE
- BROWN
- DARKBLUE
- DARKBROWN
- DARKGRAY
- DARKGREEN
- DARKPURPLE
- GOLD
- GRAY
- GREEN
- LIGHTGRAY
- LIME
- MAGENTA
- MAROON
- ORANGE
- PINK
- PURPLE
- RAYWHITE
- RED
- SKYBLUE
- VIOLET
- WHITE
- YELLOW

The `circularOrbit` attribute takes the name of another object as its value. The orbiting object's velocity will then be calculated to have a stable orbit around this central object.
The `orbitDir` attribute can be used to choose the orbit direction. However, the program doesn't currently guarantee that the orbiting object's velocity will be perpendicular to the central object's position.