#ifndef VMAINWINDOW_H
#define VMAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPair>
#include <QString>

class QLabel;
class QComboBox;
class VDirectoryTree;
class QSplitter;
class QListWidget;
class QTabWidget;
class QToolBar;
class VNote;
class QAction;
class QPushButton;
class VNotebook;
class QActionGroup;
class VFileList;
class VEditArea;
class QToolBox;
class VOutline;

class VMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    VMainWindow(QWidget *parent = 0);
    const QVector<QPair<QString, QString> > &getPalette() const;

private slots:
    void setCurNotebookIndex(int index);
    // Create a notebook
    void onNewNotebookBtnClicked();
    void onDeleteNotebookBtnClicked();
    void onNotebookInfoBtnClicked();
    void updateNotebookComboBox(const QVector<VNotebook *> &p_notebooks);
    void notebookComboBoxAdded(const VNotebook *p_notebook, int p_idx);
    void notebookComboBoxDeleted(int p_oriIdx);
    void notebookComboBoxRenamed(const VNotebook *p_notebook, int p_idx);
    void importNoteFromFile();
    void changeMarkdownConverter(QAction *action);
    void aboutMessage();
    void changeExpandTab(bool checked);
    void setTabStopWidth(QAction *action);
    void setEditorBackgroundColor(QAction *action);
    void setRenderBackgroundColor(QAction *action);
    void handleCurTabStatusChanged(const QString &notebook, const QString &relativePath,
                                   bool editMode, bool modifiable, bool modified);
    void changePanelView(QAction *action);
    void handleFileListDirectoryChanged(const QString &notebook, const QString &relativePath);
    void curEditFileInfo();
    void deleteCurNote();

signals:
    void curNotebookChanged(const QString &notebookName);

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    void setupUI();
    QWidget *setupDirectoryPanel();
    void initActions();
    void initToolBar();
    void initMenuBar();
    void initDockWindows();
    bool isConflictWithExistingNotebooks(const QString &name);
    void initPredefinedColorPixmaps();
    void initRenderBackgroundMenu(QMenu *menu);
    void initEditorBackgroundMenu(QMenu *menu);
    void changeSplitterView(int nrPanel);
    void updateWindowTitle(const QString &str);
    void updateToolbarFromTabChage(bool empty, bool editMode, bool modifiable);
    void saveStateAndGeometry();
    void restoreStateAndGeometry();

    // If true, comboBox changes will not trigger any signal out
    bool notebookComboMuted;
    VNote *vnote;

    QString curEditNotebook;
    QString curEditRelativePath;

    QLabel *notebookLabel;
    QLabel *directoryLabel;
    QComboBox *notebookComboBox;
    QPushButton *newNotebookBtn;
    QPushButton *deleteNotebookBtn;
    QPushButton *notebookInfoBtn;
    VFileList *fileList;
    VDirectoryTree *directoryTree;
    QSplitter *mainSplitter;
    VEditArea *editArea;
    QDockWidget *toolDock;
    QToolBox *toolBox;
    VOutline *outline;

    // Actions
    QAction *newRootDirAct;
    QAction *newNoteAct;
    QAction *noteInfoAct;
    QAction *deleteNoteAct;
    QAction *editNoteAct;
    QAction *saveNoteAct;
    QAction *saveExitAct;
    QAction *discardExitAct;
    QActionGroup *viewAct;
    QAction *twoPanelViewAct;
    QAction *onePanelViewAct;
    QAction *expandViewAct;
    QAction *importNoteAct;
    QActionGroup *converterAct;
    QAction *markedAct;
    QAction *hoedownAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *expandTabAct;
    QActionGroup *tabStopWidthAct;
    QAction *twoSpaceTabAct;
    QAction *fourSpaceTabAct;
    QAction *eightSpaceTabAct;
    QActionGroup *backgroundColorAct;
    QActionGroup *renderBackgroundAct;

    // Menus
    QMenu *viewMenu;

    QVector<QPixmap> predefinedColorPixmaps;
};

#endif // VMAINWINDOW_H
