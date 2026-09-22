#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

struct Particle {
sf::CircleShape shape;
sf::Vector2f velocity;
float baseSpeed;
};

float randomFloat(float min, float max) {
return min + static_cast<float>(rand()) /
static_cast<float>(RAND_MAX) * (max - min);
}

Particle createParticle(float screenWidth, float startY) {
Particle p;

float radius = randomFloat(2.0f, 4.0f);

p.shape.setRadius(radius);
p.shape.setOrigin(radius, radius);

p.shape.setPosition(
randomFloat(0.0f, screenWidth),
startY
);

p.baseSpeed = randomFloat(180.0f, 320.0f);

p.velocity = sf::Vector2f(
randomFloat(-15.0f, 15.0f),
p.baseSpeed
);

p.shape.setFillColor(
sf::Color(220, 240, 255, 230)
);

return p;
}

int main() {

srand(static_cast<unsigned>(time(nullptr)));

sf::VideoMode desktop =
sf::VideoMode::getDesktopMode();

const float SCREEN_W =
static_cast<float>(desktop.width);

const float SCREEN_H =
static_cast<float>(desktop.height);

sf::RenderWindow window(
desktop,
"Particle Force Field",
sf::Style::Fullscreen
);

window.setFramerateLimit(60);

const int PARTICLE_COUNT = 5000;

std::vector<Particle> particles;

particles.reserve(PARTICLE_COUNT);

for (int i = 0; i < PARTICLE_COUNT; i++) {

particles.push_back(
createParticle(
SCREEN_W,
randomFloat(0.0f, SCREEN_H)
)
);
}

sf::Clock clock;

while (window.isOpen()) {

sf::Event event;

while (window.pollEvent(event)) {

if (event.type == sf::Event::Closed) {
window.close();
}

if (
event.type == sf::Event::KeyPressed &&
event.key.code == sf::Keyboard::Escape
) {
window.close();
}
}

float dt =
clock.restart().asSeconds();

if (dt > 0.033f) {
dt = 0.033f;
}

sf::Vector2i mousePixel =
sf::Mouse::getPosition(window);

sf::Vector2f mouse =
window.mapPixelToCoords(mousePixel);

for (Particle& p : particles) {

sf::Vector2f position =
p.shape.getPosition();

float dx =
position.x - mouse.x;

float dy =
position.y - mouse.y;

float distance =
std::sqrt(
dx * dx +
dy * dy
);

const float FORCE_RADIUS = 80.0f;

if (
distance < FORCE_RADIUS &&
distance > 0.01f
) {


float force =
(FORCE_RADIUS - distance)
/ FORCE_RADIUS;

float directionX =
dx / distance;

float directionY =
dy / distance;

const float FORCE_STRENGTH =
18000.0f;

p.velocity.x +=
directionX *
force *
FORCE_STRENGTH *
dt;

p.velocity.y +=
directionY *
force *
FORCE_STRENGTH *
dt;
}

if (p.velocity.y < p.baseSpeed) {

p.velocity.y +=
400.0f * dt;

if (p.velocity.y > p.baseSpeed) {
p.velocity.y =
p.baseSpeed;
}
}

p.velocity.x *=
0.96f;


p.shape.move(
p.velocity * dt
);


if (
p.shape.getPosition().y >
SCREEN_H + 10.0f
) {

p = createParticle(
SCREEN_W,
randomFloat(-50.0f, -5.0f)
);
}
}

window.clear(
sf::Color(10, 12, 20)
);

for (const Particle& p : particles) {
window.draw(p.shape);
}

window.display();
}

return 0;
}