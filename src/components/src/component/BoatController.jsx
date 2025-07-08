import React, { useState } from 'react';
import axios from 'axios';
import {
  FaArrowAltCircleUp,
  FaArrowAltCircleRight,
  FaArrowAltCircleLeft,
  FaArrowAltCircleDown
} from "react-icons/fa";
import { FaAngleDoubleUp } from "react-icons/fa";
import { FaAngleDoubleDown } from "react-icons/fa";

import { IoMdFlashlight } from "react-icons/io";

const BASE_URL = import.meta.env.VITE_BACKEND_URL; // Backend proxy

// 🧠 Send movement commands
const sendCommand = async (command) => {
  try {
    await axios.get(`${BASE_URL}/move/${command}`);
    console.log("Sent:", command);
  } catch (error) {
    console.error('Backend error:', error);
  }
};

const BoatController = () => {
  const [speed, setSpeed] = useState(5); // speed level (0-9)
  const sendSpeedToESP = async (value) => {
    try {
      await axios.get(`${BASE_URL}/move/${value}`);
      console.log(`Speed set to ${value}`);
    } catch (err) {
      console.error('Failed to send speed:', err);
    }
  };

  const handleSpeedChange = (e) => {
    const value = e.target.value;
    setSpeed(value);
    sendSpeedToESP(value);
  };

  // 📱🔥 Press and hold handlers
  const pressHandlers = (direction) => ({
    onMouseDown: () => sendCommand(direction),
    onMouseUp: () => sendCommand('S'),
    onMouseLeave: () => sendCommand('S'),
    onTouchStart: () => sendCommand(direction),
    onTouchEnd: () => sendCommand('S'),
  });

  const BoatOnOff = async (value) => {
    console.log(value)
    try {
      await axios.get(`${BASE_URL}/move/${value}`);
      console.log(`${value}`);
    } catch (err) {
      console.error(err);
    }
  };

  

  return (
    <div className='px-5 py-7 pb-10 lg:px-100'>
      <div className='w-full bg-gray-50 h-20 border border-gray-200 rounded-md'></div>

      <div className='w-full px-10 max-sm:px-5 mt-6'>
        {/* First Row */}
        <div className='flex items-center justify-between my-3'>
          <button {...pressHandlers('I')} className='text-3xl bg-white border border-gray-300 shadow-md rounded-md py-4 px-6 cursor-pointer'>
            <FaArrowAltCircleUp className='rotate-[-45deg]' />
          </button>
          <button {...pressHandlers('F')} className='text-3xl bg-white border border-gray-300 shadow-md rounded-md py-4 px-6 cursor-pointer'>
            <FaArrowAltCircleUp />
          </button>
          <button {...pressHandlers('G')} className='text-3xl bg-white border border-gray-300 shadow-md rounded-md py-4 px-6 cursor-pointer'>
            <FaArrowAltCircleUp className='rotate-[45deg]' />
          </button>
        </div>

        {/* Second Row */}
        <div className='flex justify-between items-center my-3'>
          <button {...pressHandlers('L')} className='text-3xl bg-white border border-gray-300 shadow-md rounded-md py-4 px-6 cursor-pointer'>
            <FaArrowAltCircleLeft />
          </button>
          <button className='text-3xl bg-white border border-gray-300 shadow-md rounded-md py-4 px-6 cursor-pointer'>
            <IoMdFlashlight className='text-yellow-600' />
          </button>
          <button {...pressHandlers('R')} className='text-3xl bg-white border border-gray-300 shadow-md rounded-md py-4 px-6 cursor-pointer'>
            <FaArrowAltCircleRight />
          </button>
        </div>

        {/* Third Row */}
        <div className='flex items-center justify-between my-3'>
          <button {...pressHandlers('J')} className='text-3xl bg-white border border-gray-300 shadow-md rounded-md py-4 px-6 cursor-pointer'>
            <FaArrowAltCircleDown className='rotate-[45deg]' />
          </button>
          <button {...pressHandlers('B')} className='text-3xl bg-white border border-gray-300 shadow-md rounded-md py-4 px-6 cursor-pointer'>
            <FaArrowAltCircleDown />
          </button>
          <button {...pressHandlers('H')} className='text-3xl bg-white border border-gray-300 shadow-md rounded-md py-4 px-6 cursor-pointer'>
            <FaArrowAltCircleDown className='rotate-[-45deg]' />
          </button>
        </div>
      </div>

      {/* Speed Slider */}
      <div className="w-full max-w-xl mx-auto mt-10 px-4">
        <h2 className="text-xl font-semibold mb-4 text-center">Speed Control</h2>
        <div className="flex items-center gap-4">
          <span className="text-sm">Low</span>
          <input
            type="range"
            min="0"
            max="9"
            value={speed}
            onChange={handleSpeedChange}
            className="w-full h-2 bg-gray-300 rounded-lg appearance-none cursor-pointer accent-blue-500"
          />
          <span className="text-sm">High</span>
        </div>
        <p className="text-center mt-3 text-sm text-gray-600">
          Current Speed Level: <span className="font-bold">{speed}</span>
        </p>
      </div>
      <h1 className='my-4'>Servo up & down -</h1>
      <div className='flex items-center justify-between mt-2'>
        <button {...pressHandlers('sup')} className='text-3xl bg-white border border-gray-300 shadow-md rounded-md py-4 px-6 cursor-pointer'>
          <FaAngleDoubleUp />
        </button>
        <button {...pressHandlers('sdown')} className='text-3xl bg-white border border-gray-300 shadow-md rounded-md py-4 px-6 cursor-pointer'>
          <FaAngleDoubleDown />
        </button>
      </div>

    <div className='px-2 py-2 mt-6 border-1 border-gray-300 bg-gray-100 shadow-md inset-shadow-gray-50 rounded-md '>
      <div className=''>
        <h1 className='text-[]18px font-medium text-gray-600'>Convayor -</h1>
        <div className='flex justify-between items-center mt-3'>
        <button onClick={()=>BoatOnOff("con")} className='text-[20px] active:bg-white active:text-green-500 active:border active:border-green-500 bg-green-500 text-white border border-gray-300 shadow-md rounded-md py-1.5 px-8 cursor-pointer'>
            Start
        </button>
        <button onClick={()=>BoatOnOff("coff")} className='text-[20px] active:bg-white active:text-red-500 active:border active:border-red-500 bg-red-500 text-white border border-gray-300 shadow-md rounded-md py-1.5 px-8 cursor-pointer'>
            Stop
        </button>
        </div>
      </div>

      <div className='mt-6'>
        <h1 className='text-[]18px font-medium text-gray-600'>Gurbage Dumping -</h1>
        <div className='flex justify-between items-center mt-3'>
        <button onClick={()=>BoatOnOff("gon")} className='text-[20px] active:bg-white active:text-green-500 active:border active:border-green-500 bg-green-500 text-white border border-gray-300 shadow-md rounded-md py-1.5 px-8 cursor-pointer'>
            Start
        </button>
        <button onClick={()=>BoatOnOff("goff")} className='text-[20px] active:bg-white active:text-red-500 active:border active:border-red-500 bg-red-500 text-white border border-gray-300 shadow-md rounded-md py-1.5 px-8 cursor-pointer'>
            Stop
        </button>
        </div>
      </div>
      </div>
    </div>
  );
};

export default BoatController;
