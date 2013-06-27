/***************************************************************************
**
** Copyright (C) 2010, 2011 Nokia Corporation and/or its subsidiary(-ies).
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/
#include <QApplication>
#include <QList>
#include <QPair>
#include <QSize>
#include <QString>

#include "common.h"

QList<QPair<QString,QSize> > Common::getPixmapsToRequest() {
    // list of ids requested when browsing around in widgetsgallery
    QList<QPair<QString,QSize> > pixmapsToRequest;
    pixmapsToRequest
            << QPair<QString,QSize>("icon-m-framework-list", QSize(30, 30))
            << QPair<QString,QSize>("icon-m-framework-grid", QSize(30, 30))
            << QPair<QString,QSize>("icon-l-gallery", QSize(0, 0))
            << QPair<QString,QSize>("icon-l-video", QSize(30, 30))
            << QPair<QString,QSize>("icon-m-toolbar-send-sms", QSize(30, 30))
            << QPair<QString,QSize>("icon-l-contacts", QSize(30, 30))
            << QPair<QString,QSize>("meegotouch-button-background-disabled-selected", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-disabled", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-horizontal-center", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-horizontal-left", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-horizontal-right", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-pressed-horizontal-center", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-pressed-horizontal-left", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-pressed-horizontal-right", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-pressed", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-selected-horizontal-center", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-selected-horizontal-left", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-selected-horizontal-right", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background-selected", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-background", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-checkbox-background-pressed", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-checkbox-background-selected", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-checkbox-background", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-checkbox-inverted-background-pressed", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-checkbox-inverted-background-selected", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-checkbox-inverted-background", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-disabled-selected", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-disabled", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-horizontal-center", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-horizontal-left", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-horizontal-right", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-pressed-horizontal-center", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-pressed-horizontal-left", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-pressed-horizontal-right", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-pressed", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-selected-horizontal-center", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-selected-horizontal-left", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-selected-horizontal-right", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background-selected", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-inverted-background", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-radiobutton-background-pressed", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-radiobutton-background-selected", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-radiobutton-background", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-radiobutton-inverted-background-pressed", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-radiobutton-inverted-background-selected", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-button-radiobutton-inverted-background", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-panel-background-pressed", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-panel-inverted-background-pressed", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-positionindicator-indicator", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-sheet-button-accent-background-selected", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-sheet-button-accent-inverted-background-selected", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-slider-elapsed-background-horizontal-disabled", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-slider-elapsed-background-vertical-disabled", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-slider-elapsed-inverted-background-horizontal-disabled", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-slider-elapsed-inverted-background-vertical-disabled", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-slider-handle-background-disabled", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-slider-received-background-vertical-disabled", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-slider-received-inverted-background-vertical-disabled", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-text-editor-bottom-tail", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-text-editor-top-tail", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-text-selection-handle", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-textedit-background-disabled", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-textedit-background-error", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-textedit-background-selected", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-textedit-background", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-toolbar-landscape-background", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-toolbar-landscape-inverted-background", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-toolbar-portrait-background", QSize(0, 0))
            << QPair<QString,QSize>("meegotouch-toolbar-portrait-inverted-background", QSize(0, 0))
            << QPair<QString,QSize>("icon-m-framework-home", QSize(50, 50))
            << QPair<QString,QSize>("icon-m-framework-back", QSize(50, 50))
            << QPair<QString,QSize>("icon-m-framework-close", QSize(50, 50))
            ;
    return pixmapsToRequest;
}

void Common::printResults(const QString& serverType, QMap<QString, RequestInfo> answeredRequests, QMap<QString, RequestInfo> unansweredRequests)
{
    QTextStream log(stdout, QIODevice::WriteOnly | QIODevice::Text);
    log << "###Timing results for " << serverType << "###" << '\n';

    const int idWidth = 60;
    log << left << qSetFieldWidth(idWidth) << "Pixmap Id" << qSetFieldWidth(0) << "Delay" << '\n';

    QMapIterator<QString, RequestInfo> iter(answeredRequests);
    while (iter.hasNext()) {
        iter.next();
        log << qSetFieldWidth(idWidth) << iter.key() << qSetFieldWidth(0) << iter.value().delay() << "ms" << '\n';
    }

    if (!unansweredRequests.isEmpty()) {
        log << '\n';
        log << "The following pixmap requests have not been answered by the themedaemon: ";
        QMapIterator<QString, RequestInfo> iter(unansweredRequests);
        while (iter.hasNext()) {
            iter.next();
            log << iter.key() << " ";
        }
    }
    log << '\n';
    log.flush();
}
