# 🌱 Smart Greenhouse IoT Berbasis ESP32 dan Blynk

> **Proyek Akhir Mata Kuliah Sistem Mikrokontroler**
> Departemen Informatika - Universitas Teknologi Bandung

---

## 📖 Deskripsi Proyek

Smart Greenhouse merupakan sistem monitoring dan kontrol greenhouse berbasis **Internet of Things (IoT)** yang menggunakan **ESP32** sebagai mikrokontroler utama dan **Blynk Cloud** sebagai platform monitoring serta kontrol jarak jauh.

Sistem ini mampu memonitor **suhu**, **kelembapan**, dan **intensitas cahaya** secara real-time, kemudian mengendalikan **kipas**, **lampu greenhouse**, dan **ventilasi otomatis** berdasarkan kondisi lingkungan.

Selain bekerja secara otomatis, pengguna juga dapat mengontrol lampu dan ventilasi secara manual melalui aplikasi **Blynk** di smartphone.

---

# 👨‍🎓 Informasi Proyek

| Keterangan         | Informasi                                     |
| ------------------ | --------------------------------------------- |
| **Mata Kuliah**    | Sistem Mikrokontroler                         |
| **Judul Proyek**   | Smart Greenhouse IoT Berbasis ESP32 dan Blynk |
| **Dosen Pengampu** | Muchamad Rusdan, S.T., M.T.                   |
| **Universitas**    | Universitas Teknologi Bandung                 |
| **Nama**           | **Wendi Rahmawan**                                 |
| **NIM**            | **23552011208**                                  |

---

# 🎯 Tujuan Proyek

* Melakukan monitoring suhu secara real-time.
* Melakukan monitoring kelembapan udara.
* Mendeteksi kondisi terang dan gelap menggunakan sensor LDR.
* Mengontrol kipas secara otomatis ketika suhu meningkat.
* Mengontrol lampu greenhouse secara otomatis saat kondisi gelap.
* Mengontrol ventilasi greenhouse menggunakan motor servo.
* Menampilkan data sensor pada dashboard Blynk.
* Memberikan kontrol manual melalui smartphone.

---

# 🛠️ Komponen yang Digunakan

| Komponen     | Fungsi                        |
| ------------ | ----------------------------- |
| ESP32 DevKit | Mikrokontroler utama          |
| DHT22        | Sensor suhu dan kelembapan    |
| LDR Module   | Sensor intensitas cahaya      |
| Relay Module | Mengendalikan kipas           |
| Servo Motor  | Membuka dan menutup ventilasi |
| LED          | Simulasi lampu greenhouse     |
| LCD I2C 16x2 | Menampilkan informasi lokal   |
| Blynk Cloud  | Monitoring dan kontrol IoT    |

---

# ⚙️ Cara Kerja Sistem

1. ESP32 membaca suhu dan kelembapan menggunakan sensor **DHT22**.
2. ESP32 membaca intensitas cahaya menggunakan **LDR**.
3. Data dikirim secara real-time ke **Blynk Cloud**.
4. Sistem menjalankan kontrol otomatis:

   * **Suhu > 30°C → Relay (kipas) aktif**
   * **Siang + Suhu > 32°C → Ventilasi terbuka**
   * **Gelap → Lampu greenhouse menyala**
5. Pengguna juga dapat mengontrol lampu dan ventilasi secara manual melalui aplikasi Blynk.

---

# ✨ Fitur Sistem

✅ Monitoring suhu

✅ Monitoring kelembapan

✅ Monitoring intensitas cahaya

✅ Monitoring melalui smartphone

✅ Kipas otomatis

✅ Lampu otomatis

✅ Ventilasi otomatis

✅ Kontrol manual lampu

✅ Kontrol manual ventilasi

---

# 🖥️ Rangkaian Wokwi

<img width="935" height="873" alt="rangkaian" src="https://github.com/user-attachments/assets/9f06cf4f-042e-4635-a5a1-7d7ef133c341" />

---

# 📱 Dashboard Blynk

<img width="722" height="1600" alt="blynk" src="https://github.com/user-attachments/assets/3a1a1bde-faf6-41e7-96e7-8c289228004d" />

---

# 📂 Struktur Program

Program terdiri dari beberapa bagian utama:

* Inisialisasi WiFi dan Blynk
* Pembacaan sensor DHT22
* Pembacaan sensor LDR
* Pengiriman data ke Blynk
* Kontrol otomatis relay (kipas)
* Kontrol otomatis servo (ventilasi)
* Kontrol otomatis lampu greenhouse
* Kontrol manual melalui aplikasi Blynk
* Tampilan data pada LCD

---

# 🚀 Hasil Pengujian

| Pengujian             | Hasil      |
| --------------------- | ---------- |
| Monitoring suhu       | ✅ Berhasil |
| Monitoring kelembapan | ✅ Berhasil |
| Monitoring cahaya     | ✅ Berhasil |
| Kipas otomatis        | ✅ Berhasil |
| Lampu otomatis        | ✅ Berhasil |
| Ventilasi otomatis    | ✅ Berhasil |
| Kontrol Blynk         | ✅ Berhasil |
| LCD I2C               | ✅ Berhasil |

---

# 🔗 Tautan Proyek

### 💻 Wokwi

https://wokwi.com/projects/466919701234903041

### 🎥 YouTube

https://youtu.be/Tk2OG1kNktw

---

# 📌 Kesimpulan

Proyek **Smart Greenhouse IoT Berbasis ESP32 dan Blynk** berhasil diimplementasikan menggunakan ESP32 sebagai pusat kendali. Sistem mampu melakukan monitoring suhu, kelembapan, dan intensitas cahaya secara real-time serta mengendalikan kipas, lampu, dan ventilasi secara otomatis maupun manual melalui aplikasi Blynk. Dengan penerapan teknologi IoT, proses pemantauan dan pengendalian greenhouse menjadi lebih mudah, efisien, dan dapat dilakukan dari mana saja melalui koneksi internet.

---

## ⭐ Terima Kasih

Proyek ini dibuat sebagai **Proyek Akhir Mata Kuliah Sistem Mikrokontroler** di **Universitas Teknologi Bandung**.
