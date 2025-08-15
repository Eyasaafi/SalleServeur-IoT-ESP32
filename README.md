# SalleServeur-IoT-ESP32
Système IoT de surveillance et commande d’une salle serveur avec ESP32, capteurs environnementaux et application mobile.
Système IoT complet de surveillance et de commande d’une salle serveur, basé sur une carte ESP32 et intégrant des capteurs environnementaux (DHT11 pour la température et l’humidité, MQ2 pour la détection de gaz) ainsi que des actionneurs (ventilateur, buzzer et lampe via relais).
Le système lit en temps réel les données des capteurs et réagit automatiquement aux dépassements de seuils prédéfinis en activant les actionneurs correspondants. 
Une application mobile, développée avec MIT App Inventor et connectée en Bluetooth, permet à l’utilisateur de consulter à distance les mesures (température, humidité, niveau de gaz) et de commander manuellement le ventilateur et le buzzer. 
Ce projet vise à améliorer la sécurité et la maintenance préventive des environnements critiques comme les salles serveurs, et propose également des pistes d’évolution vers une version industrielle avec des capteurs professionnels (Testo 162 T1, Senseair S8) et une supervision avancée via cloud ou alertes SMS/e-mail.
**Auteur :** Eya Saafi  
**Encadrant :** Mr. Bedoui Mouafak  
**Année universitaire :** 2024-2025  
