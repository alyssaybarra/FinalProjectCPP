# Papas-Biologeria

Papa's Biologeria is an immersive educational experience designed to delve into the intricate intersection of data science and biology. This interactive game is meticulously crafted to facilitate a comprehensive understanding of fundamental concepts within the realm of data science applications in biology.

## Overview
Welcome to the 3D laboratory setting of Papa's Biologeria! Embark on an enlightening journey guided by an AI companion, Jeffery, who adeptly navigates users through a spectrum of biological phenomena. Witness firsthand how these phenomena can be intricately modeled and comprehended using cutting-edge bioinformatics techniques.

## Key Features
Immersive 3D Environment: Step into a captivating laboratory setting that brings the world of biology to life.
AI Guidance: Engage with an AI companion who expertly elucidates complex biological concepts and their correlation with data science methodologies.
Informative Conversations: Interact with the AI guide to learn about the fusion of biological concepts with data science methodologies.
Educational Insights: Gain foundational knowledge about how  bioinformatics intersect with biology.
Conceptual Understanding: Explore theoretical connections between data science techniques and their potential applications in a biological context.



## Installation and dependencies
To ensure this project runs smoothly, you'll need to install the Epic Games Launcher (for Unreal Engine 5.3.2) and JetBrains Rider IDE. It's crucial to avoid opening this application in CLion as it may lead to operational inconsistencies. Additionally, it's worth noting that specific code segments in this project aren't designed for compilation within an IDE. However, they are optimized for successful compilation within the Unreal Engine Editor. To open this application simply open the FinalProjectCPP.UProject file and it will automatically open in the unreal editor. Under Unreal Editor -> Prefrences -> Source Code -> and change the source code editor to Rider. From there it will prompt you to restart the launcher. Once you have done that on the top bar under tools there is an option called Open in Rider click that for access into the code in Rider. 

The source code for building the models and visualizations from biological data can be found in this [repository](https://github.com/annika6246/BioExploration). This code was stored separately since it has a cmake configuration, which is not compatible with Rider IDE but is for one such as CLion. This program does not require any command line elements to run as the data used is already included in the repository, and the driver can be modified to take different input files. Running this program requires both the MLPack and SeqAn libraries to be installed as well as their dependencies (which include armadillo, ensmallen, and cereal).

## Usage guide
To open the game in Unreal Engine, select "Recent Projects" then "Browse" and navigate to where the ".uproject" file is stored in your file directory, then select "open". From the contents folder, select the Lab level and click the run button while making sure you are within the map. Once running, the user can move using arrow keys or "WASD" and once within the sightline of the AI teacher, the teacher will follow the user's movement. Pressing "e" allows the user to read the educational dialogue while observing the relevant visualizations. To exit the game, press the escape key.



## Gameplay visuals
![](https://im5.ezgif.com/tmp/ezgif-5-e82da92b95.gif)



![](https://im.ezgif.com/tmp/ezgif-1-be8e276c18.gif)


<img src="https://im5.ezgif.com/tmp/ezgif-5-24ef6f9f95.jpg" width="901" height="536"/>


## Links to external libraries
[MLPack](https://github.com/mlpack): A C++ library that provides efficient implementation of a variety of machine learning algorithms

[SeqAn (version 2.4)](https://github.com/seqan): A C++ library for processing and analyzing biological sequences.

[Unreal Editor](https://www.unrealengine.com/en-US/): A 3D creation platform for game development.
