// BROKEN CODE
// #include <iostream>
// #include <vector>
// #include <string>

// class UIWidget {
// public:
//     virtual void render() const {
//         std::cout << "[Generic Widget]\n";
//     }
// };

// class Button : public UIWidget {
// private:
//     std::string m_label;
// public:
//     Button(std::string label) : m_label(label) {}
//     void render() const override {
//         std::cout << "[Button: " << m_label << "]\n";
//     }
// };

// int main() {
//     std::vector<UIWidget> canvas;
    
//     // Add a specialized button to our layout canvas
//     canvas.push_back(Button("Submit"));
    
//     // Render the canvas
//     for (const auto& widget : canvas) {
//         widget.render(); // Problem: Outputs "[Generic Widget]" instead of "[Button: Submit]"!
//     }
// }
// FIXED CODE
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class UIWidget {
public:
    virtual void render() const {
        std::cout << "[Generic Widget]\n";
    }
};

class Button : public UIWidget {
private:
    std::string m_label;
public:
    Button(std::string label) : m_label(label) {}
    void render() const override {
        std::cout << "[Button: " << m_label << "]\n";
    }
};

int main() {
    std::vector<std::unique_ptr<UIWidget>> canvas;
    //the generic widget was printing beacuse the slot in vector is only 16 byte
    // hoever the button class 40bytes>8 byte vptr ans 32 byte string< which causes object slicing, slices the string in button completeely
    // and vector contains a vptr only, pointing to base class, causu=ing miss print,
    // we can increse slot size dynamically by unique_ptr
    
    // Add a specialized button to our layout canvas
    canvas.push_back(std::make_unique<Button>("Submit"));
    
    // Render the canvas
    for (const auto& widget : canvas) {
        widget->render(); // Problem: Outputs "[Generic Widget]" instead of "[Button: Submit]"!
    }
}

