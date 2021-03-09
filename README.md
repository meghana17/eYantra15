# Autonomous Puzzle Solver Robot

The arena is a combination of 2 grids with obstacles present at certain edges and vertices - the left grid containing 1-digit numbers and right grid contatining 2-digit numbers that can be obtained by adding the nubers in the left grid. The task is to solve the mathematical puzzle in the least time by recognizing the digits in the image captured by the robot’s camera and picking the set of numbers on the left grid that add up to a 2‑digit number on the right grid and dropping them.

![test_image1](https://user-images.githubusercontent.com/14092419/110543988-0f106980-8151-11eb-9194-0ac58df530dd.jpg)


The task is performed using image processing and digit recognition in Python with OpenCV, using input from solely an overhead webcam. All the number markers and obstacles are detected and overall efficient path is planned using A* algorithm.
