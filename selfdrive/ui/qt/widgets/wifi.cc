#include "selfdrive/ui/qt/widgets/wifi.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

WiFiPromptWidget::WiFiPromptWidget(QWidget *parent) : QFrame(parent) {
  QVBoxLayout *main_layout = new QVBoxLayout(this);
  main_layout->setContentsMargins(48, 48, 48, 32);
  main_layout->setSpacing(32);

  QHBoxLayout *title_layout = new QHBoxLayout;
  {
    // TODO: icon pixmap
    QLabel *title = new QLabel(tr("Setup Wi-Fi"));
    title->setStyleSheet("font-size: 64px; font-weight: bold;");
    title_layout->addWidget(title);
    title_layout->addStretch();
  }
  main_layout->addLayout(title_layout);

  QLabel *desc = new QLabel(tr("Connect to Wi-Fi to upload driving data and help improve openpilot"));
  desc->setStyleSheet("font-size: 36px;");
  desc->setWordWrap(true);
  main_layout->addWidget(desc);

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
  main_layout->addWidget(settings_btn, 0, Qt::AlignHCenter);

  setFixedWidth(750);
  setStyleSheet(R"(
    WiFiPromptWidget {
      background-color: #333333;
      border-radius: 10px;
    }
  )");
}
