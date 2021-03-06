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

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <memory>

#include <QMainWindow>

#include "objects_scene.hpp"
#include "simulation_controller.hpp"

namespace Ui
{
    class MainWindow;
}

class MainWindow: public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow();
        MainWindow(const MainWindow &) = delete;
        ~MainWindow();
        MainWindow& operator=(const MainWindow &) = delete;

    private:
        std::unique_ptr<Ui::MainWindow> ui;

        ObjectsScene m_scene;
        SimulationController m_controller;
};

#endif // MAINWINDOW_HPP
