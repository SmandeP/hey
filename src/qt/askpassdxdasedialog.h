// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_ASKPASSDXDASEDIALOG_H
#define BITCOIN_QT_ASKPASSDXDASEDIALOG_H

#include <QDialog>

class WalletModel;

namespace Ui
{
class AskPassdxdaseDialog;
}

/** Multifunctional dialog to ask for passdxdases. Used for encryption, unlocking, and changing the passdxdase.
 */
class AskPassdxdaseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,         /**< Ask passdxdase twice and encrypt */
        UnlockAnonymize, /**< Ask passdxdase and unlock only for anonymization */
        Unlock,          /**< Ask passdxdase and unlock */
        ChangePass,      /**< Ask old passdxdase + new passdxdase twice */
        Decrypt          /**< Ask passdxdase and decrypt wallet */
    };

    explicit AskPassdxdaseDialog(Mode mode, QWidget* parent, WalletModel* model);
    ~AskPassdxdaseDialog();

    void accept();

private:
    Ui::AskPassdxdaseDialog* ui;
    Mode mode;
    WalletModel* model;
    bool fCapsLock;

private slots:
    void textChanged();

protected:
    bool event(QEvent* event);
    bool eventFilter(QObject* object, QEvent* event);
};

#endif // BITCOIN_QT_ASKPASSDXDASEDIALOG_H
