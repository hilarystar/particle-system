Particle Force Field
A real-time particle simulation built with C++ and SFML.

The project creates hundreds of particles that continuously fall across the screen while responding to the movement of the mouse through a dynamic force field.

Features
600+ independently simulated particles
Randomized particle positions, sizes, and speeds
Gravity-based downward movement
Interactive mouse force field
Particles are pushed away from the cursor
Automatic particle respawning
Fullscreen rendering
Real-time 60 FPS simulation
How It Works
Each particle stores:

Position
Velocity
Base falling speed
Size
Every frame, the program:

Calculates the particle’s distance from the mouse.
Applies a repulsive force when the particle enters the force field.
Applies gravity to restore its downward movement.
Updates the particle’s position.
Respawns particles after they leave the screen.
The force field becomes stronger as a particle gets closer to the cursor.

Built With
C++
SFML
Object-oriented programming
Vector mathematics
Basic physics simulation
Controls
Mouse: Move the cursor to interact with the particles.

ESC: Exit fullscreen.

Running the Project
Make sure SFML is installed and configured for your C++ compiler.

Compile the project with your SFML libraries, then run the resulting executable.

What I Learned
This project helped me practice:

C++ structs and objects
Vectors and arrays
Loops and iteration
Random number generation
Delta time and frame-independent movement
Distance calculations
Vector-based forces
Basic particle physics
Real-time rendering with SFML
Future Improvements
Possible additions include:

Particle color transitions
Different particle behaviors
Multiple force fields
Adjustable gravity
Particle trails
Wind simulation
Interactive sliders for physics parameters
Performance optimization for thousands of particles