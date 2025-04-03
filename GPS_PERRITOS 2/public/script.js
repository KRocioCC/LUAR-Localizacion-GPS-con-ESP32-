// Configuración de Firebase
const firebaseConfig = {
  apiKey: "AIzaSyAtlsBmuO4naYA7Ht1lI6m3tGWJo9fcUHU",
  authDomain: "gps-perritos.firebaseapp.com",
  databaseURL: "https://gps-perritos-default-rtdb.firebaseio.com",
  projectId: "gps-perritos",
  storageBucket: "gps-perritos.firebasestorage.app",
  messagingSenderId: "938910828746",
  appId: "1:938910828746:web:1d89ed67f6b2d978c4cc33",
  measurementId: "G-661PFW0GEW"
};
firebase.initializeApp(firebaseConfig);
const db = firebase.database();

// Inicializar el mapa
const map = L.map('map').setView([-16.54494, -68.18338], 15); // Coordenadas iniciales
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
  maxZoom: 19,
  attribution: '© OpenStreetMap contributors'
}).addTo(map);

// Marcador inicial
const gpsMarker = L.marker([-16.54494, -68.18338]).addTo(map).bindPopup('Ubicación del GPS').openPopup();

// Función para actualizar el marcador
function updateMarker(lat, lng) {
  gpsMarker.setLatLng([lat, lng]).bindPopup(`Latitud: ${lat}, Longitud: ${lng}`).openPopup();
  map.setView([lat, lng], 15); // Centrar el mapa en las nuevas coordenadas
}

// Escuchar cambios en Firebase
const gpsRef = db.ref('/gps');
gpsRef.on('value', (snapshot) => {
  const data = snapshot.val();
  if (data) {
    updateMarker(data.latitude, data.longitude); // Actualizar el marcador con los datos de Firebase
  }
});
