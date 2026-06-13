<div align="center">

# 🖥️ SalleServeur-IoT-ESP32

**Système IoT de surveillance et de commande d'une salle serveur**

[![ESP32](https://img.shields.io/badge/ESP32-Espressif-red?style=flat-square&logo=espressif)](https://www.espressif.com/)
[![MIT App Inventor](https://img.shields.io/badge/App-MIT%20App%20Inventor-blue?style=flat-square)](https://appinventor.mit.edu/)
[![Bluetooth](https://img.shields.io/badge/Connectivité-Bluetooth-0082FC?style=flat-square&logo=bluetooth)](https://www.bluetooth.com/)
[![License](https://img.shields.io/badge/Licence-MIT-green?style=flat-square)](LICENSE)

</div>

---

## 📌 Description

Système IoT complet de surveillance et de commande d'une salle serveur, basé sur une carte **ESP32** et intégrant des capteurs environnementaux ainsi que des actionneurs pilotés par relais.

Le système lit en **temps réel** les données des capteurs et réagit automatiquement aux dépassements de seuils prédéfinis. Une **application mobile Bluetooth** permet à l'utilisateur de consulter à distance les mesures et de commander manuellement les actionneurs.

---

## 📸 Aperçu

<div align="center">

<img width="1364" height="612" alt="Architecture du système" src="https://github.com/user-attachments/assets/e2483ef1-b06c-44f6-bf58-4a3ac31afa10" />

<br/><br/>

<img width="851" height="638" alt="Application mobile" src="https://github.com/user-attachments/assets/8545ba3d-9843-474b-896b-bac716c9f1d2" />

</div>

---

## ⚙️ Composants matériels

| Composant | Rôle |
|-----------|------|
| **ESP32** | Microcontrôleur principal — WiFi & Bluetooth intégré |
| **DHT11** | Capteur de température et d'humidité |
| **MQ-2** | Capteur de détection de gaz (fumée, GPL, CO) |
| **Ventilateur** | Refroidissement automatique via relais |
| **Buzzer** | Alarme sonore en cas de dépassement de seuil |
| **Lampe** | Signalisation visuelle via relais |

---

## 📱 Application mobile

Développée avec **MIT App Inventor**, l'application se connecte à l'ESP32 via **Bluetooth** et permet de :

- Consulter en temps réel la **température**, l'**humidité** et le **niveau de gaz**
- Commander manuellement le **ventilateur** et le **buzzer**
- Recevoir des alertes visuelles en cas de dépassement de seuils

---

## 🔄 Fonctionnement

```
Lecture capteurs (DHT11 + MQ-2)
        │
        ▼
Comparaison aux seuils prédéfinis
        │
   ┌────┴────┐
   │         │
Seuil OK   Seuil dépassé
   │         │
  Idle     Activation actionneur
           (ventilateur / buzzer / lampe)
        │
        ▼
Envoi données → Application mobile (Bluetooth)
```

---

## 🗂️ Structure du projet

```
SalleServeur-IoT-ESP32/
├── firmware/
│   └── main.ino              # Code principal ESP32
├── app/
│   └── SalleServeur.aia      # Projet MIT App Inventor
├── docs/
│   ├── schéma_câblage.png    # Schéma de câblage
│   └── rapport.pdf           # Rapport technique
└── README.md
```

---

## 🚀 Installation et utilisation

### 1. Prérequis

- [Arduino IDE](https://www.arduino.cc/en/software) avec le support ESP32 installé
- Bibliothèques Arduino : `DHT sensor library`, `BluetoothSerial`
- Application **MIT App Inventor** ou APK fourni dans `/app`

### 2. Flasher le firmware

```bash
# Cloner le dépôt
git clone https://github.com/Eyasaafi/SalleServeur-IoT-ESP32.git
cd SalleServeur-IoT-ESP32

# Ouvrir firmware/main.ino dans Arduino IDE
# Sélectionner la carte : ESP32 Dev Module
# Téléverser sur la carte
```

### 3. Lancer l'application mobile

1. Installer l'APK sur votre smartphone Android
2. Activer le Bluetooth
3. Appairer avec le module ESP32
4. Lancer l'application et se connecter

---

## 🔭 Évolutions envisagées

| Évolution | Description |
|-----------|-------------|
| **Capteurs professionnels** | Remplacement DHT11 → Testo 162 T1 (précision industrielle) |
| **Capteur CO₂** | Intégration Senseair S8 pour surveillance qualité d'air |
| **Supervision cloud** | Tableau de bord via MQTT / Node-RED / Grafana |
| **Alertes à distance** | Notifications SMS ou e-mail en cas d'alerte critique |
| **Historique des données** | Enregistrement et visualisation des tendances |

---

## 👩‍💻 Auteure

<div align="center">

| <img src="https://github.com/Eyasaafi.png" width="80" style="border-radius:50%"/> |
|:---:|
| **Eya Saafi** |
| [@Eyasaafi](https://github.com/Eyasaafi) |

</div>

---

<div align="center">

*Projet réalisé dans le cadre d'un système embarqué IoT pour environnements critiques.*

</div>
