# Roadmap

### Linux 
#### Input Utilities - done
- getch - done
- scanw - done
- mvscanw - done
- mvscanw - done
  
#### Output Utilities
- move - done
- write - done
- wwrite - done
- mvwrite - done
- mvwwrite - done
- chgat
- mvchgat

#### Color utilities
- has_colors
- start_color
- init_pair

#### Mouse Utilities
- mousemask
- getmouse

#### Keyboard Utilities
- keypad

#### Screen Utilities
- refresh - done
- getscreenlimits - done
- noecho - done
- echo - done
- attron
- attroff
- attrset
- attr_get

#### Window Utilities
- createwindow - done
- wborder - done
- wrefresh - done
- wattron
- wattroff
- wattrset
- wattr_get
  
#### Screendumping Utilities - done
- initscreen - done
- screendump - done
- screenrestore - done


<br>
### Windows
#### Input Utilities
- getch
- scanw
- mvscanw
- mvscanw
  
#### Output Utilities
- move
- write
- wwrite
- mvwrite
- mvwwrite
- chgat
- mvchgat

#### Color utilities
- has_colors
- start_color
- init_pair

#### Mouse Utilities
- mousemask
- getmouse

#### Keyboard Utilities
- keypad

#### Screen Utilities
- refresh
- getscreenlimits
- noecho
- echo
- attron
- attroff
- attrset
- attr_get

#### Window Utilities
- createwindow
- wborder
- wrefresh
- wattron
- wattroff
- wattrset
- wattr_get
  
#### Screendumping Utilities
- initscreen
- screendump
- screenrestore

<br>
### Common

- Interface
- Character, levels, stats, and stats-combat relation definition
- Combat system and mechanics definition
- Environnment interaction mechanics (movement, use / search for items / things, NPC dialogues, etc)
- Monsters / creatures / enemies definition (see [Notes](#otes))
- Equipment (AKA stuff) definition (rarity, droprates, etc)
- Dungeons defintion (see [Notes](#notes))

#### Quests
- Quest manager (see [Notes](#notes))
- Quest generator
- Storyline (AKA Scenario) (if any)

<br>
### Notes
Future feature : Players may be able to create their own Quests, Dongeons and enemies using config files.<br>
The implementations will come once the related definition is complete.<br>