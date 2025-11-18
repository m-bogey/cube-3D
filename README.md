Cub3D is a 42 school team graphic design project where you need to create a 3D dynamic view in a maze, inspired by Wolfenstein 3D. Coding in C and using the MiniLibX library, an adaptation of the Xlib library, we must implement ray-casting algorithms. 

Mandatory

    Using ray-casting algorithm and the minilibx library
    Show different textures depending on the wall orientation (north, south, east, west)
    Ceiling and floor colors
    Assets depend on an infile that should be correctly formatted
    Moving with W, A, S, D and closing with ESC
    Rotate left and right with arrow
    Wall collisions
    Minimap system

Clone the repository and enter it :

git clone https://github.com/m-bogey/cub3d
cd cub3d
make

The minilibx library is not included in this repository, the latest version will be cloned while making the project.
The program takes a map file as an argument. It should be correctly formated :

    .cub format only
    Every texture file linked (NO, SO, WE, EA) - ex: WE ./path_to_the_west_texture
    Floor F and ceiling color C, in R,G,B range [0,255] : 0, 255, 255 - ex: F 220,100,0
    Map should be composed only of :
    0 for empty spaces
    1 for walls
    N, S, W, E for the player start orientation
    In bonus part : D for a door
    Elements can be mixed and separated with whitespaces

You can find maps in the maps/ directory. Maps in error/ directory are incorrectly formatted. Make sure you use _bonus maps with bonus part only, to avoid an error.
From the project directory, chose your version of the project, then link the map.

./cub3d maps/map.cub

ebriere / m-bogey
