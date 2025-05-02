#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include<iostream>

// Class representing a simulated network connection
class Connection {
private:
    std::string id;       // Connection ID (e.g., "Conn-1")
    float transferRate;   // Current simulated bandwidth in Bytes per second

public:
    Connection(const std::string& id_) : id(id_), transferRate(0.0f) {}

    // Randomly generate a transfer rate within the given bounds
    void simulateTransfer(float minRate, float maxRate) {
        static std::mt19937 gen(std::random_device{}()); // Random number generator
        std::uniform_real_distribution<float> dist(minRate, maxRate);
        transferRate = dist(gen);
    }

    float getRate() const { return transferRate; }
    const std::string& getId() const { return id; }
};

// Class for monitoring and visualizing bandwidth usage of connections
class BandwidthMonitor {
private:
    std::vector<Connection> connections; // List of simulated connections
    sf::RenderWindow window;             // SFML window for rendering
    sf::Font font;                       // Font used for text labels

    const int width = 1600;   // Window width
    const int height = 1200;  // Window height
    const float minRate = 1000.0f;   // Minimum bandwidth rate
    const float maxRate = 5000.0f;   // Maximum bandwidth rate

public:
    BandwidthMonitor(int numConnections) 
        : window(sf::VideoMode(width, height), "OOP Bandwidth Monitor") {
        
        // Create specified number of connections with IDs like "Conn-1"
        for (int i = 0; i < numConnections; ++i) {
            connections.emplace_back("Conn-" + std::to_string(i + 1));
        }

        // Load font for rendering text on screen
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
            throw std::runtime_error("Font file not found.");
        }
    }

    // Main loop: handle events, simulate data, and draw graphics
    void run() {
        while (window.isOpen()) {
            handleEvents();
            simulateAll();
            drawAll();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Wait 1 second
        }
    }

private:
    // Handles window events like closing
    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    // Simulate bandwidth for all connections
    void simulateAll() {
        for (auto& conn : connections) {
            conn.simulateTransfer(minRate, maxRate);
        }
    }

    // Draw the bar graph of all connection rates
    void drawAll() {
        window.clear(sf::Color::Black); // Clear screen

        // Find maximum transfer rate to normalize bar heights
        float maxTransfer = 0.0f;
        for (const auto& conn : connections)
            if (conn.getRate() > maxTransfer)
                maxTransfer = conn.getRate();

        float barWidth = width / (connections.size() * 2.0f); // Space for each bar

        // Draw each connection's bar and label
        for (size_t i = 0; i < connections.size(); ++i) {
            const Connection& conn = connections[i];

            float heightRatio = conn.getRate() / maxTransfer;
            float barHeight = heightRatio * (height - 100); // Leave margin for labels
            float x = i * 2 * barWidth + barWidth / 2;
            float y = height - barHeight;

            // Create and draw the green bar
            sf::RectangleShape bar(sf::Vector2f(barWidth, barHeight));
            bar.setPosition(x, y);
            bar.setFillColor(sf::Color::Green);
            window.draw(bar);

            // Display connection ID and transfer rate above the bar
            sf::Text label(conn.getId() + ": " + std::to_string(static_cast<int>(conn.getRate())) + " B/s",
                           font, 14);
            label.setPosition(x, y - 20);
            label.setFillColor(sf::Color::White);
            window.draw(label);
        }

        window.display(); // Show the drawn frame
    }
};

// Entry point
int main() {
    try {
        BandwidthMonitor monitor(5);  // Create a monitor for 5 connections
        monitor.run();                // Start the monitoring loop
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
