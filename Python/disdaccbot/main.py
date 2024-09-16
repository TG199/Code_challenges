#!/usr/bin/python3
"""A simple Discord bot"""
import os
from os import getenv
import discord
from discord.ext import commands
import json
from command_function import get_quote, get_challenge, add_to_list, get_list, get_count
from dotenv import load_dotenv

load_dotenv()
intents = discord.Intents.default()
intents.message_content = True
bot = commands.Bot(command_prefix='!', intents=intents)


try:
    with open("challenges.json", mode="r") as json_file:
        data = json.load(json_file)
        challenges = data["challenges"]
except Exception as e:
        print(f"Error! {e}")
        challenges = []
    

@bot.event
async def on_ready():
    print(f"Bot logged in as {bot.user}")

@bot.event
async def on_message(message: discord.Message):
    if message.author == bot.user:
        return
    
    msg = message.content
    if msg.lower().startswith("hello"):
        await message.channel.send(f"Hello, {message.author.name}!")
    await bot.process_commands(message)

@bot.command()
async def quote(cmd):
    quote = get_quote()
    await cmd.channel.send(quote)

@bot.command()
async def challenge(cmd):
    challenge = get_challenge(challenges)
    await cmd.channel.send(challenge)

@bot.command()
async def add(cmd, challenge):
    await cmd.send(challenge)

@bot.command()
async def list(cmd):
    cmd_list = get_list(challenges)
    await cmd.channel.send(cmd_list)

@bot.command()
async def count(cmd):
    total_challenges = get_count(challenges)
    await cmd.channel.send(f"Total challenges is: {total_challenges}")

token = getenv('TOKEN')

if token is None:
    raise ValueError("Please set the TOKEN environment variable.")
bot.run(token)



