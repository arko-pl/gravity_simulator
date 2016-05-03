/*
 * Scene for graviting objects
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

#include "objects_scene.hpp"

#include <cassert>

#include <QGraphicsItem>

ObjectsScene::ObjectsScene()
{

}


ObjectsScene::~ObjectsScene()
{

}


void ObjectsScene::addObject(int id, const QPointF& p)
{
    const QSizeF size(1e6, 1e6);
    const QRectF rect(p, size);

    QGraphicsItem* item = addEllipse(rect, QPen(), QBrush(Qt::SolidPattern));
    m_objects.insert( std::make_pair(id, item) );
    item->setVisible(true);
}


void ObjectsScene::updatePosition(int id, const QPointF& pos)
{
    auto obj = m_objects.find(id);
    assert(obj != m_objects.end());

    obj->second->setPos(pos);
}
