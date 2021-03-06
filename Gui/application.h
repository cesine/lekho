/*
*  Lekho v1.0 will be a simple editor for bangla in unicode that will export
*  to bangtex
*  Copyright (C) 2001,2002 Kaushik Ghose kghose@wam.umd.edu
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software
*  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
*/

/* this file will get bigger and bigger as the interface gets more complicated, but
   BanglaTextEdit and BanglaDocument etc. shouldn't be affected....

*/
/****************************************************************************
** $Id$
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef APPLICATION_H
#define APPLICATION_H

#include <qdir.h>
#include <qfiledialog.h>
#include <qmainwindow.h>
#include <qstringlist.h>

#include <lekhostream.h>

#include <BanglaTextEdit.h>
#include <lekhoprefs.h>
//#include <preferences.h>


class ApplicationWindow: public QMainWindow
{
    Q_OBJECT

//initialisation
public:
    ApplicationWindow(QStringList &sl);
    ~ApplicationWindow();

protected:
    void readPrefs();
    void initialiseParser();
    void initialiseScreenFontConverter();
    void initialiseLatexConverter();

protected:
    void closeEvent( QCloseEvent* );
//    void contentsMousePressEvent ( QMouseEvent *mausevent );

public:
    void printDebug();

private slots:
	void newDoc();
	void newDoc(QStringList &fl);
	void choose();
	void load( const QString &fileName );
	void save();
	void saveAs();
	void saveAsHTML();
	void saveAsUTF16();
	void HTMLexport();
	void HTMLexportAs();
	void LaTeXexport();
	void LaTeXexportAs();

	void copy();	//all utf-16 ops
	void paste();
	void cut();
	void undo();
	void redo();

	void print();

	void find();
	void spellCheck();

	void setWordWrap(bool ww);
	void setCursorBlink(bool cb);
	void setSyntaxHighlighting(bool);

	void chooseEnglishFont();
	void chooseBanglaFont();
	void chooseForeground();
	void chooseBackground();
	void chooseSyntaxColor();

	void setTabWidth();

	void keyMapHelp();
	void about();
	void aboutQt();

public slots:

    void documentModified( bool ) ;
    void statusBarMessage(const QString&) ;
    void errorMessage(const QString&) ;

public:
    QPrinter *printer;


private:

    LekhoPrefs thePref ;
    BanglaTextEdit *e ;

    QString filename, htmlname, latexname , lekhorc;

    bool fudgeHtmlOn ;
};


#endif
