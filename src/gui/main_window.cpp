/*
 * Main window for gravity simulator
 * Copyright (C) 2016  Michał Walenciak <MichalWalenciak@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "main_window.hpp"

#include "ui_main_window.h"


MainWindow::MainWindow():
    ui(),
    m_scene(),
    m_controller()
{
    ui = std::make_unique<Ui::MainWindow>();
    ui->setupUi(this);

    ui->graphicsView->setScene(&m_scene);
    m_controller.setScene(&m_scene);

    connect(&m_controller, &SimulationController::fpsUpdated, ui->simulationInfo, &SimulationInfoWidget::updateFps);
    connect(&m_controller, &SimulationController::objectCountUpdated, ui->simulationInfo, &SimulationInfoWidget::updateObjectCount);
    connect(&m_scene, &ObjectsScene::objectDataUpdated, ui->simulationInfo, &SimulationInfoWidget::updateObjectData);
    m_controller.beginSimulation();
}


MainWindow::~MainWindow()
{

}
