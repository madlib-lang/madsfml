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
      eventData->fields[0]->value = (void *)sfmlEvent.mouseButton.button;
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
      event->index = madsfml__EventType::MouseButtonPress;
      event->data = (void *)eventData;

      result->index = madlib__maybe__Maybe_JUST_INDEX;
      result->data = event;
      break;
    }

    case sf::Event::EventType::MouseButtonReleased: {
      madlib__record__Record_t *eventData =
          (madlib__record__Record_t *)GC_MALLOC(
              sizeof(madlib__record__Record_t));
      eventData->fieldCount = 3;
      eventData->fields = (madlib__record__Field_t **)GC_MALLOC(
          sizeof(madlib__record__Field_t *) * 3);
      eventData->fields[0] =
          (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t));
      eventData->fields[0]->name = (char *)"button";
      eventData->fields[0]->value = (void *)sfmlEvent.mouseButton.button;
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
      event->index = madsfml__EventType::MouseButtonRelease;
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
