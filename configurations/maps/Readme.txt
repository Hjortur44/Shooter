Map Index:
**********
The index is stored in the file 'index.json' (under the 'maps' folder).
The structure follows the standard rules of the JSON file format.

The structure of the index file:
********************************
---------------------------------------------------------------------------
|           Looks               |               Description               |
---------------------------------------------------------------------------
| {                             |                                         |
|   "domainFolder": <string>,   | Domain folder (one above 'src' folder). |
| 	"maps":             		    | The map list.                           |
|		[ 	                        |                                         |
|			{                         |                                         |
| 			"configPath": <string>, | The configuration file path.            |
| 			"number": <integer>     | The number of the map.                  |
| 		},                        |                                         |
|			{                         |                                         |
| 			"configPath": <string>, |                                         |
| 			"number": <integer>     |                                         |
| 		}                         |                                         |
|	           .                  |                                         |
|	           .                  |                                         |
|	           .                  |                                         |
|			{                         |                                         |
| 			"configPath": <string>, |                                         |
| 			"number": <integer>     |                                         |
| 		}                         |                                         |
|		]                           |                                         |
| }                             |                                         |
---------------------------------------------------------------------------


The structure of the configuration file for the map textures (confFile):
************************************************************************
----------------------------------------------------------------
|           Looks             |          Description           |
----------------------------------------------------------------
| {                           |                                |
|		"textures":               | The texture list.              |
|		[                         |                                |
|			{                       |                                |
|				"name": <string>,     | The name of the texture.       |
|				"path": <string>,     | The path to the texture file.  |
|				"positions": <list>   | The position list on the grid. |
|			},                      |                                |
|			{                       |                                |
|				"name": <string>,     |                                |
|				"path": <string>,     |                                |
|				"positions": <list>   |                                |
|			},                      |                                |
|	           .                |                                |
|	           .                |                                |
|	           .                |                                |
|			{                       |                                |
|				"name": <string>,     |                                |
|				"path": <string>,     |                                |
|				"positions": <list>   |                                |
|			}                       |                                |
|		]                         |                                |
| }                           |                                |
----------------------------------------------------------------


Tile:
*****
---------------------------------------------------------------------
|      Name       | Id |  Type  |            Description            |
---------------------------------------------------------------------
| Accessability   | ac | string | See section "Accessability Ids".  |
| Location Column | lc |   int  | Is the column position in a grid. |
| Location Row    | lr |   int  | Is the row position in a grid.    |
| Size Height     | sh |   int  | 32 pixels (assumed).              |
| Size Width      | sw |   int  | 32 pixels (assumed).              |
| Texture         | tx | string | The name of the texture file.     |
---------------------------------------------------------------------


Accessability Ids:
******************
--------------------------
| Id |    Description    |
--------------------------
| D  | Destructable tile |
| I  | Interactable tile |
| O  | Passable tile     |
| X  | Impassable tile   |
--------------------------