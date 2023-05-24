#include "selfdrive/ui/qt/widgets/wifi.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QStackedLayout>

WiFiPromptWidget::WiFiPromptWidget(QWidget *parent) : QFrame(parent) {
  QStackedLayout *stack = new QStackedLayout(this);

  // Setup Wi-Fi
  QFrame *setup = new QFrame;
  setup->setContentsMargins(40, 20, 40, 8);
  QVBoxLayout *setup_layout = new QVBoxLayout(setup);
  setup_layout->setSpacing(24);
  {
    QHBoxLayout *title_layout = new QHBoxLayout;
    title_layout->setSpacing(32);
    {
      QLabel *icon = new QLabel;
      QPixmap *pixmap = new QPixmap("../assets/offroad/icon_wifi_strength_full.svg");
      icon->setPixmap(pixmap->scaledToHeight(64, Qt::SmoothTransformation));
      title_layout->addWidget(icon);

      QLabel *title = new QLabel(tr("Setup Wi-Fi"));
      title->setStyleSheet("font-size: 64px; font-weight: bold;");
      title_layout->addWidget(title);
      title_layout->addStretch();
    }
    setup_layout->addLayout(title_layout);

    QLabel *desc = new QLabel(tr("Connect to Wi-Fi to upload driving data and help improve openpilot"));
    desc->setStyleSheet("font-size: 36px;");
    desc->setWordWrap(true);
    setup_layout->addWidget(desc);

    QPushButton *settings_btn = new QPushButton(tr("Open Settings"));
    settings_btn->setStyleSheet(R"(
      QPushButton {
        font-size: 48px;
        font-weight: 500;
        border-radius: 10px;
        background-color: #465BEA;
        padding: 32px 96px;
      }
      QPushButton:pressed {
        background-color: #3049F4;
      }
    )");
    setup_layout->addWidget(settings_btn, 0, Qt::AlignHCenter);

    setup_layout->addStretch();
  }
  stack->addWidget(setup);

  // Uploading data
  QFrame *uploading = new QFrame;
  uploading->setContentsMargins(32, 0, 32, 16);
  QVBoxLayout *uploading_layout = new QVBoxLayout(uploading);
  {
    QLabel *icon = new QLabel;
    QPixmap *pixmap = new QPixmap("../assets/offroad/icon_wifi_uploading.svg");
    icon->setPixmap(pixmap->scaledToWidth(100, Qt::SmoothTransformation));
    uploading_layout->addWidget(icon, 0, Qt::AlignHCenter);

    QLabel *title = new QLabel(tr("Uploading your training data"));
    title->setAlignment(Qt::AlignHCenter);
    title->setStyleSheet("font-size: 64px; font-weight: bold;");
    title->setWordWrap(true);
    uploading_layout->addWidget(title, 0, Qt::AlignHCenter);

    QLabel *desc = new QLabel(tr("Your driving data helps improve openpilot"));
    desc->setStyleSheet("font-size: 34px;");
    desc->setWordWrap(false);
    uploading_layout->addWidget(desc, 0, Qt::AlignHCenter);

    uploading_layout->addStretch();
  }
  stack->addWidget(uploading);

  stack->setCurrentWidget(uploading);

  setFixedWidth(750);
  setStyleSheet(R"(
    WiFiPromptWidget {
      background-color: #333333;
      border-radius: 10px;
    }
  )");
}
