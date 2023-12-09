# Papas-Biologeria

## Overview
Papa's Biologeria is an educational game aimed to teach users the fundamentals related to data science applications in biology. It features a 3D lab setting where an AI walks the user through different biological phenomena and how they can be modeled using machine learning and bioinformatics techniques.

## Installation and dependencies
To ensure this project runs smoothly, you'll need to install the Epic Games Launcher (for Unreal Engine 5.3.2) and JetBrains Rider IDE. It's crucial to avoid opening this application in CLion as it may lead to operational inconsistencies. Additionally, it's worth noting that specific code segments in this project aren't designed for compilation within an IDE. However, they are optimized for successful compilation within the Unreal Engine Editor. To open this application simply open the FinalProjectCPP.UProject file and it will automatically open in the unreal editor. Under Unreal Editor -> Prefrences -> Source Code -> and change the source code editor to Rider. From there it will prompt you to restart the launcher. Once you have done that on the top bar under tools there is an option called Open in Rider click that for access into the code in Rider. 

The source code for building the models and visualizations from biological data can be found in this [repository](https://github.com/annika6246/BioExploration). This code was stored separately since it has a cmake configuration, which is not compatible with Rider IDE but is for one such as CLion. This program does not require any command line elements to run as the data used is already included in the repository, and the driver can be modified to take different input files. Running this program requires both the MLPack and SeqAn libraries to be installed as well as their dependencies (which include armadillo, ensmallen, and cereal).

## Usage guide
To open the game in Unreal Engine, select "Recent Projects" then "Browse" and navigate to where the ".uproject" file is stored in your file directory, then select "open". From the contents folder, select the Lab level and click the run button while making sure you are within the map. Once running, the user can move using arrow keys and once within the sightline of the AI teacher, the teacher will follow the user's movement. Pressing "e" allows the user to read the educational dialogue while observing the relevant visualizations. To exit the game, press the escape key.

## Gameplay visuals
![](https://im5.ezgif.com/tmp/ezgif-5-e82da92b95.gif)

<img src="https://im5.ezgif.com/tmp/ezgif-5-24ef6f9f95.jpg" width="901" height="536"/>

## Links to external libraries
[MLPack](https://github.com/mlpack): A C++ library that provides efficient implementation of a variety of machine learning algorithms

[SeqAn (version 2.4)](https://github.com/seqan): A C++ library for processing and analyzing biological sequences.

[Unreal Editor](https://www.unrealengine.com/en-US/): A 3D creation platform for game development.
