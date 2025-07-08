import express from 'express'
import cors from 'cors'
import axios from 'axios'

const app = express();
const PORT = 8000;
app.use(cors());
app.use(express.json());

// ESP8266 IP (still must be accessible from this server)
const ESP8266_IP = 'http://192.168.4.1';

app.get('/move/:dir', async (req, res) => {
  const { dir } = req.params;
  try {
    const response = await axios.get(`${ESP8266_IP}/?State=${dir}`);
    res.send({ status: 'OK', command: dir });
  } catch (error) {
    res.status(500).send({ error: 'Failed to send command', details: error.message });
  }
});

app.listen(PORT, () => {
  console.log(`Backend server running at http://localhost:${PORT}`);
});
