#include <SFML/Graphics.hpp>

#include "gc.h"
#include "maybe.hpp"
#include "number.hpp"
#include "record.hpp"

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
  MouseWheelScroll,
  SensorChange,
  Size,
  TextEnter,
  TouchEnd,
  TouchMove,
  TouchStart,
};

enum madsfml__WheelType {
  HorizontalWheel,
  VerticalWheel,
};

enum madsfml__MouseButtonIndex {
  Left,
  Middle,
  Right,
  XButton1,
  XButton2,
};

typedef struct madsfml__MouseButton {
  int64_t index;
} madsfml__MouseButton_t;

enum madsfml__JoystickAxisIndex {
  PovX,
  PovY,
  R,
  U,
  V,
  X,
  Y,
  Z,
};

typedef struct madsfml__JoystickAxis {
  int64_t index;
} madsfml__JoystickAxis_t;

typedef struct madsfml__Wheel {
  int64_t index;
} madsfml__Wheel_t;

typedef struct madsfml__Event {
  int64_t index;
  void *data;
} madsfml__Event_t;

madsfml__Event_t *buildNullaryEvent(madsfml__EventType index) {
  madsfml__Event_t *event =
      (madsfml__Event_t *)GC_MALLOC(sizeof(madsfml__Event_t));
  event->index = index;
  event->data = (void *)NULL;
  return event;
}

madlib__maybe__Maybe_t *madsfml__pollEvent(sf::RenderWindow *window) {
  sf::Event sfmlEvent;
  bool hasEvent = window->pollEvent(sfmlEvent);

  madlib__maybe__Maybe_t *result =
      (madlib__maybe__Maybe_t *)GC_MALLOC(sizeof(madlib__maybe__Maybe_t));

  if (!hasEvent) {
    result->index = madlib__maybe__Maybe_NOTHING_INDEX;
    result->data = NULL;
    return result;
  }

  switch (sfmlEvent.type) {
    case sf::Event::EventType::KeyReleased:
    case sf::Event::EventType::KeyPressed: {
      madlib__record__Record_t *eventData =
          (madlib__record__Record_t *)GC_MALLOC(
              sizeof(madlib__record__Record_t));
      eventData->fieldCount = 6;
      eventData->fields = (madlib__record__Field_t **)GC_MALLOC(
          sizeof(madlib__record__Field_t *) * 6);
      eventData->fields[0] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *)"alt";
      eventData->fields[0]->value = (void *)sfmlEvent.key.alt;
      eventData->fields[1] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *)"code";
      eventData->fields[1]->value = (void *)sfmlEvent.key.code;
      eventData->fields[2] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[2]->name = (char *)"control";
      eventData->fields[2]->value = (void *)sfmlEvent.key.control;
      eventData->fields[3] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[3]->name = (char *)"scanCode";
      eventData->fields[3]->value = (void *)sfmlEvent.key.scancode;
      eventData->fields[4] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[4]->name = (char *)"shift";
      eventData->fields[4]->value = (void *)sfmlEvent.key.shift;
      eventData->fields[5] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[5]->name = (char *)"system";
      eventData->fields[5]->value = (void *)sfmlEvent.key.system;

      madsfml__Event_t *event =
          (madsfml__Event_t *)GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = sfmlEvent.type == sf::Event::EventType::KeyPressed ? madsfml__EventType::KeyPressed : madsfml__EventType::KeyReleased;
      event->data = (void *)eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    case sf::Event::EventType::MouseButtonReleased:
    case sf::Event::EventType::MouseButtonPressed: {
      madlib__record__Record_t *eventData =
          (madlib__record__Record_t *)GC_MALLOC(
              sizeof(madlib__record__Record_t));
      eventData->fieldCount = 3;
      eventData->fields = (madlib__record__Field_t **)GC_MALLOC(
          sizeof(madlib__record__Field_t *) * 3);
      eventData->fields[0] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *)"button";
      madsfml__MouseButton_t *mouseButton = (madsfml__MouseButton_t*) GC_MALLOC(sizeof(madsfml__MouseButton_t));
      eventData->fields[0]->value = (void *)mouseButton;
      switch(sfmlEvent.joystickMove.axis) {
        case sf::Mouse::Button::Left: {
          mouseButton->index = madsfml__MouseButtonIndex::Left;
          break;
        }
        case sf::Mouse::Button::Right: {
          mouseButton->index = madsfml__MouseButtonIndex::Right;
          break;
        }
        case sf::Mouse::Button::Middle: {
          mouseButton->index = madsfml__MouseButtonIndex::Middle;
          break;
        }
        case sf::Mouse::Button::XButton1: {
          mouseButton->index = madsfml__MouseButtonIndex::XButton1;
          break;
        }
        case sf::Mouse::Button::XButton2: {
          mouseButton->index = madsfml__MouseButtonIndex::XButton2;
          break;
        }
      }
      eventData->fields[1] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *)"x";
      eventData->fields[1]->value = (void *)sfmlEvent.mouseButton.x;
      eventData->fields[2] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[2]->name = (char *)"y";
      eventData->fields[2]->value = (void *)sfmlEvent.mouseButton.y;

      madsfml__Event_t *event =
          (madsfml__Event_t *)GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = sfmlEvent.type == sf::Event::EventType::MouseButtonPressed ? madsfml__EventType::MouseButtonPress : madsfml__EventType::MouseButtonRelease;
      event->data = (void *)eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    case sf::Event::EventType::MouseMoved: {
      madlib__record__Record_t *eventData =
          (madlib__record__Record_t *)GC_MALLOC(
              sizeof(madlib__record__Record_t));
      eventData->fieldCount = 2;
      eventData->fields = (madlib__record__Field_t **)GC_MALLOC(
          sizeof(madlib__record__Field_t *) * 2);
      eventData->fields[0] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *)"x";
      eventData->fields[0]->value = (void *)sfmlEvent.mouseMove.x;
      eventData->fields[1] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *)"y";
      eventData->fields[1]->value = (void *)sfmlEvent.mouseMove.y;

      madsfml__Event_t *event =
          (madsfml__Event_t *)GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = madsfml__EventType::MouseMove;
      event->data = (void *)eventData;

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

    case sf::Event::EventType::Resized: {
      madlib__record__Record_t *eventData =
          (madlib__record__Record_t *)GC_MALLOC(
              sizeof(madlib__record__Record_t));
      eventData->fieldCount = 2;
      eventData->fields = (madlib__record__Field_t **)GC_MALLOC(
          sizeof(madlib__record__Field_t *) * 2);
      eventData->fields[0] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *)"width";
      eventData->fields[0]->value = (void *)sfmlEvent.mouseMove.x;
      eventData->fields[1] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *)"height";
      eventData->fields[1]->value = (void *)sfmlEvent.mouseMove.y;

      madsfml__Event_t *event =
          (madsfml__Event_t *)GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = madsfml__EventType::Size;
      event->data = (void *)eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    case sf::Event::EventType::TextEntered: {
      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = (void*) sfmlEvent.text.unicode;
    }

    case sf::Event::EventType::MouseWheelScrolled: {
      madlib__record__Record_t *eventData =
          (madlib__record__Record_t *)GC_MALLOC(
              sizeof(madlib__record__Record_t));
      eventData->fieldCount = 4;
      eventData->fields = (madlib__record__Field_t **)GC_MALLOC(
          sizeof(madlib__record__Field_t *) * 4);
      eventData->fields[0] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *)"delta";
      eventData->fields[0]->value = (void *) boxDouble(sfmlEvent.mouseWheelScroll.delta);
      eventData->fields[1] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *)"wheel";
      madsfml__Wheel_t* wheel = (madsfml__Wheel_t*) GC_MALLOC(sizeof(madsfml__Wheel_t));
      wheel->index = sfmlEvent.mouseWheelScroll.wheel == sf::Mouse::Wheel::HorizontalWheel ? HorizontalWheel : VerticalWheel;
      eventData->fields[1]->value = (void *) wheel;
      eventData->fields[2] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[2]->name = (char *)"x";
      eventData->fields[2]->value = (void *)sfmlEvent.mouseWheelScroll.x;
      eventData->fields[3] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[3]->name = (char *)"y";
      eventData->fields[3]->value = (void *)sfmlEvent.mouseWheelScroll.y;

      madsfml__Event_t *event =
          (madsfml__Event_t *)GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = madsfml__EventType::MouseWheelScroll;
      event->data = (void *)eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = (void*) event;
      break;
    }

    case sf::Event::EventType::JoystickButtonReleased:
    case sf::Event::EventType::JoystickButtonPressed: {
      madlib__record__Record_t *eventData =
          (madlib__record__Record_t *)GC_MALLOC(
              sizeof(madlib__record__Record_t));
      eventData->fieldCount = 2;
      eventData->fields = (madlib__record__Field_t **)GC_MALLOC(
          sizeof(madlib__record__Field_t *) * 2);
      eventData->fields[0] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *)"button";
      eventData->fields[0]->value = (void *)sfmlEvent.joystickButton.button;
      eventData->fields[1] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *)"joystickId";
      eventData->fields[1]->value = (void *)sfmlEvent.joystickButton.joystickId;
      madsfml__Event_t *event =
          (madsfml__Event_t *)GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = sfmlEvent.type == sf::Event::EventType::JoystickButtonPressed ? madsfml__EventType::JoystickButtonPress : madsfml__EventType::JoystickButtonRelease;
      event->data = (void *)eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    case sf::Event::EventType::JoystickMoved: {
      madlib__record__Record_t *eventData =
          (madlib__record__Record_t *)GC_MALLOC(
              sizeof(madlib__record__Record_t));
      eventData->fieldCount = 3;
      eventData->fields = (madlib__record__Field_t **)GC_MALLOC(
          sizeof(madlib__record__Field_t *) * 3);
      eventData->fields[0] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *)"axis";
      madsfml__JoystickAxis_t *joystickAxis = (madsfml__JoystickAxis_t*) GC_MALLOC(sizeof(madsfml__JoystickAxis_t));
      eventData->fields[0]->value = (void *)joystickAxis;
      switch(sfmlEvent.joystickMove.axis) {
        case sf::Joystick::Axis::PovX: {
          joystickAxis->index = madsfml__JoystickAxisIndex::PovX;
          break;
        }
        case sf::Joystick::Axis::PovY: {
          joystickAxis->index = madsfml__JoystickAxisIndex::PovY;
          break;
        }
        case sf::Joystick::Axis::R: {
          joystickAxis->index = madsfml__JoystickAxisIndex::R;
          break;
        }
        case sf::Joystick::Axis::U: {
          joystickAxis->index = madsfml__JoystickAxisIndex::U;
          break;
        }
        case sf::Joystick::Axis::V: {
          joystickAxis->index = madsfml__JoystickAxisIndex::V;
          break;
        }
        case sf::Joystick::Axis::X: {
          joystickAxis->index = madsfml__JoystickAxisIndex::X;
          break;
        }
        case sf::Joystick::Axis::Y: {
          joystickAxis->index = madsfml__JoystickAxisIndex::Y;
          break;
        }
        case sf::Joystick::Axis::Z: {
          joystickAxis->index = madsfml__JoystickAxisIndex::Z;
          break;
        }
      }
      eventData->fields[1] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *)"joystickId";
      eventData->fields[1]->value = (void *)sfmlEvent.joystickMove.joystickId;
      eventData->fields[2] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[2]->name = (char *)"position";
      eventData->fields[2]->value = (void *)boxDouble(sfmlEvent.joystickMove.position);
      madsfml__Event_t *event =
          (madsfml__Event_t *)GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = madsfml__EventType::JoystickMove;
      event->data = (void *)eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    case sf::Event::EventType::JoystickDisconnected:
    case sf::Event::EventType::JoystickConnected: {
      madlib__record__Record_t *eventData =
          (madlib__record__Record_t *)GC_MALLOC(
              sizeof(madlib__record__Record_t));
      eventData->fieldCount = 1;
      eventData->fields = (madlib__record__Field_t **)GC_MALLOC(
          sizeof(madlib__record__Field_t *) * 1);
      eventData->fields[0] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *)"joystickId";
      eventData->fields[0]->value = (void *)sfmlEvent.joystickMove.joystickId;
      madsfml__Event_t *event =
          (madsfml__Event_t *)GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = sfmlEvent.type == sf::Event::EventType::JoystickConnected ? madsfml__EventType::JoystickConnect : madsfml__EventType::JoystickDisconnect;
      event->data = (void *)eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    case sf::Event::EventType::TouchBegan:
    case sf::Event::EventType::TouchMoved:
    case sf::Event::EventType::TouchEnded: {
      madlib__record__Record_t *eventData =
          (madlib__record__Record_t *)GC_MALLOC(
              sizeof(madlib__record__Record_t));
      eventData->fieldCount = 3;
      eventData->fields = (madlib__record__Field_t **)GC_MALLOC(
          sizeof(madlib__record__Field_t *) * 3);
      eventData->fields[0] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *)"finger";
      eventData->fields[0]->value = (void *)sfmlEvent.touch.finger;
      eventData->fields[1] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[1]->name = (char *)"x";
      eventData->fields[1]->value = (void *)sfmlEvent.touch.x;
      eventData->fields[2] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[2]->name = (char *)"y";
      eventData->fields[2]->value = (void *)sfmlEvent.touch.y;
      madsfml__Event_t *event =
          (madsfml__Event_t *)GC_MALLOC(sizeof(madsfml__Event_t));
      event->index = sfmlEvent.type == sf::Event::EventType::TouchBegan ? madsfml__EventType::TouchStart : sf::Event::EventType::TouchMoved ? madsfml__EventType::TouchMove : madsfml__EventType::TouchEnd;
      event->data = (void *)eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    default: {
      std::cout << sfmlEvent.type << std::endl;
      result->index = madlib__maybe__Maybe_NOTHING_INDEX;
      break;
    }
  }

  return result;
}

#ifdef __cplusplus
}
#endif
