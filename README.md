# -- cub3d --

## Usage (mac only) -- 👈

<img src="https://github.com/NetworkFlux/cub3d/blob/main/imgs/example.png">

```bash
git clone https://github.com/NetworkFlux/cub3d.git && cd cub3d && make && ./cub3d maps/main_map.cub
```

You might get some warnings at compilation, don't worry they come from the minilibx and won't affect the project.

## Topics -- 🗝
1. Raycasting
2. Graphics
3. 3D

## Challenge -- 💡
This project is about trying to recreate de functionalities of the famous game : Wolfenstein3D.

## Objectives -- ✅
This program will launch a game instance depending on the map given as parameter. The program handels :
- Minimap
- Texture choices
- Sprite interactions

## Rules -- 🚨
The maps must be defined as follows :

<img src="https://github.com/NetworkFlux/cub3d/blob/main/imgs/map_example.png">

Where :
- Each directions must be followed by a path referering to a texture located in the texture folder
- F stands for 'Floor' and C for 'Ceiling'. Those two are followed by an RGB code which will be the corresponding floor and ceiling color
- The actual map shape. 1 for walls, 0 for empty spaces, P for Player, K for the key and D for the door. The map should also always be closed or you will get an error.

Feel free to try it out with your own custom maps, but be carefull to make a valid map.

👍 Thanks to [swautelet](https://github.com/swautelet "swautelet GitHub") for his help, we did this together ! 👍
