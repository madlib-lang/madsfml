#include <SFML/Graphics.hpp>
#include "gc.h"
#include "record.hpp"
#include "maybe.hpp"

#ifdef __cplusplus
extern "C" {
#endif

enum madsfml__EventType {
  Close,
  FocusGain,
  FocusLoss,
  JoystickButtonPress,
  JoystickButtonRelease,
  JoystickConnect,
  JoystickDisconnect,
  JoystickMove,
  KeyPressed,
  KeyReleased,
  MouseButtonPress,
  MouseButtonRelease,
  MouseEnter,
  MouseLeave,
  MouseMove,
  MouseWheelMove,
  MouseWheelScroll,
  SensorChange,
  Size,
  TextEnter,
  TouchEnd,
  TouchMove,
  TouchStart,
};

typedef struct madsfml__Event {
  int64_t index;
  void *data;
} madsfml__Event_t;


sf::RenderWindow *madsfml__createWindow(int64_t w, int64_t h, char *name) {
  return new sf::RenderWindow(sf::VideoMode(w, h), std::string(name));
}


void madsfml__closeWindow(sf::RenderWindow *window) {
  window->close();
}


void madsfml__display(sf::RenderWindow *window) {
  window->display();
}


void madsfml__clearWindow(int32_t color, sf::RenderWindow *window) {
  window->clear(sf::Color(color));
}


madsfml__Event_t *buildNullaryEvent(madsfml__EventType index) {
  madsfml__Event_t *event = (madsfml__Event_t *) GC_MALLOC(sizeof(madsfml__Event_t));
  event->index = index;
  event->data = (void *) NULL;
  return event;
}

madlib__maybe__Maybe_t *madsfml__pollEvent(sf::RenderWindow *window) {
  sf::Event event;
  bool hasEvent = window->pollEvent(event);

  madlib__maybe__Maybe_t *result = (madlib__maybe__Maybe_t *) GC_MALLOC(sizeof(madlib__maybe__Maybe_t));

  if (!hasEvent) {
    result->index = madlib__maybe__Maybe_NOTHING_INDEX;
    result->data = NULL;
    return result;
  }

  switch (event.type) {
    case sf::Event::EventType::KeyPressed: {
      madlib__record__Record_t *eventData = (madlib__record__Record_t *) GC_MALLOC(sizeof(madlib__record__Record_t));
      eventData->fieldCount = 6;
      eventData->fields = (madlib__record__Field_t **) GC_MALLOC(sizeof(madlib__record__Field_t*) * 6);
      eventData->fields[0] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *) "alt";
      eventData->fields[0]->value = (void*) event.key.alt;
      eventData->fields[1] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *) "code";
      eventData->fields[1]->value = (void*) event.key.code;
      eventData->fields[2] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[2]->name = (char *) "control";
      eventData->fields[2]->value = (void*) event.key.control;
      eventData->fields[3] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[3]->name = (char *) "scanCode";
      eventData->fields[3]->value = (void*) event.key.scancode;
      eventData->fields[4] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[4]->name = (char *) "shift";
      eventData->fields[4]->value = (void*) event.key.shift;
      eventData->fields[5] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[5]->name = (char *) "system";
      eventData->fields[5]->value = (void*) event.key.system;

      madsfml__Event_t *event = (madsfml__Event_t *) GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = madsfml__EventType::KeyPressed;
      event->data = (void *) eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    case sf::Event::EventType::MouseButtonPressed: {
      madlib__record__Record_t *eventData = (madlib__record__Record_t *) GC_MALLOC(sizeof(madlib__record__Record_t));
      eventData->fieldCount = 3;
      eventData->fields = (madlib__record__Field_t **) GC_MALLOC(sizeof(madlib__record__Field_t*) * 3);
      eventData->fields[0] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *) "button";
      eventData->fields[0]->value = (void*) event.mouseButton.button;
      eventData->fields[1] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *) "x";
      eventData->fields[1]->value = (void*) event.mouseButton.x;
      eventData->fields[2] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[2]->name = (char *) "y";
      eventData->fields[2]->value = (void*) event.mouseButton.y;

      madsfml__Event_t *event = (madsfml__Event_t *) GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = madsfml__EventType::MouseButtonPress;
      event->data = (void *) eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    case sf::Event::EventType::MouseButtonReleased: {
      madlib__record__Record_t *eventData = (madlib__record__Record_t *) GC_MALLOC(sizeof(madlib__record__Record_t));
      eventData->fieldCount = 3;
      eventData->fields = (madlib__record__Field_t **) GC_MALLOC(sizeof(madlib__record__Field_t*) * 3);
      eventData->fields[0] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *) "button";
      eventData->fields[0]->value = (void*) event.mouseButton.button;
      eventData->fields[1] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *) "x";
      eventData->fields[1]->value = (void*) event.mouseButton.x;
      eventData->fields[2] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[2]->name = (char *) "y";
      eventData->fields[2]->value = (void*) event.mouseButton.y;

      madsfml__Event_t *event = (madsfml__Event_t *) GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = madsfml__EventType::MouseButtonRelease;
      event->data = (void *) eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    case sf::Event::EventType::MouseMoved: {
      madlib__record__Record_t *eventData = (madlib__record__Record_t *) GC_MALLOC(sizeof(madlib__record__Record_t));
      eventData->fieldCount = 2;
      eventData->fields = (madlib__record__Field_t **) GC_MALLOC(sizeof(madlib__record__Field_t*) * 2);
      eventData->fields[0] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *) "x";
      eventData->fields[0]->value = (void*) event.mouseMove.x;
      eventData->fields[1] = (madlib__record__Field_t *) GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *) "y";
      eventData->fields[1]->value = (void*) event.mouseMove.y;

      madsfml__Event_t *event = (madsfml__Event_t *) GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = madsfml__EventType::MouseMove;
      event->data = (void *) eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    case sf::Event::EventType::MouseEntered: {
      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = buildNullaryEvent(madsfml__EventType::MouseEnter);
      break;
    }

    case sf::Event::EventType::MouseLeft: {
      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = buildNullaryEvent(madsfml__EventType::MouseLeave);
      break;
    }

    case sf::Event::EventType::GainedFocus: {
      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = buildNullaryEvent(madsfml__EventType::FocusGain);
      break;
    }

    case sf::Event::EventType::LostFocus: {
      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = buildNullaryEvent(madsfml__EventType::FocusLoss);
      break;
    }

    case sf::Event::EventType::Closed: {
      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = buildNullaryEvent(madsfml__EventType::Close);
      break;
    }

    default: {
      result->index = madlib__maybe__Maybe_NOTHING_INDEX;
      break;
    } 
  }

  return result;
}

void run() {
  // create the window
    // sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 600), "My window");

    // window->isOpen();
    // sf::Event event;
    // window->pollEvent(event);
    // window->clear(sf::Color::Black);
    // window->display();

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        window.pollEvent(event);
        // while (window.pollEvent(event))
        // {
            // "close requested" event: we close the window
            // if (event.type == sf::Event::Closed)
            //     window.close();
        // }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        // end the current frame
    }
        window.display();
}

#ifdef __cplusplus
}
#endif
