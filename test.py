import requests
import logging
from telegram.ext import Updater, CommandHandler, MessageHandler, Filters
"""
url = "https://open-api.coinglass.com/api/pro/v1/futures/longShort_chart?symbol=BTC&interval=2"
params = {}
headers = {
  'coinglassSecret': '00736ebc1bb04a6fbfe5cd9668bd5555'
}
response = requests.get(url, headers=headers, data = params)
list_of_dicts = response.json()
print(list_of_dicts["data"]["longRateList"][0])
"""
# Enable logging
logging.basicConfig(
    format="%(asctime)s - %(name)s - %(levelname)s - %(message)s", level=logging.INFO
)

logger = logging.getLogger(__name__)
# Define a few command handlers. These usually take the two arguments update and
# context. Error handlers also receive the raised TelegramError object in error.
def start(update, context):
    chat_id = update.message.chat.id
    print(chat_id)
    """Send a message when the command /start is issued."""
    update.message.reply_text("請輸入時間段(1h, 4h, 12h, 24h)")
    #(1h=2, 4h=1, 12h=4, 24h=5)
    
def error(update, context):
    """Log Errors caused by Updates."""
    logger.warning('Update "%s" caused error "%s"', update, context.error)

def getratio(update, context):
    command = update.message.text
    """
    print(command)
    chat_id = update.message.chat.id
    print(chat_id)
    """
    if command == "1h":
        print(command)
        url = "https://open-api.coinglass.com/api/pro/v1/futures/longShort_chart?symbol=BTC&interval=2"
        params = {}
        headers = {
        'coinglassSecret': '00736ebc1bb04a6fbfe5cd9668bd5555',
        'Cache-Control': 'no-cache'
        }
        response = requests.get(url, headers=headers, data = params)
        list_of_dicts = response.json()
        output = "幣安多："+ str(list_of_dicts["data"]["longRateList"][0]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][0])+"%\n歐易多：" + str(list_of_dicts["data"]["longRateList"][1]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][1])+"%\nBitget多："+ str(list_of_dicts["data"]["longRateList"][3]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][3])+"%"
        update.message.reply_text(output)

    elif command == "4h":
        print(command)
        url = "https://open-api.coinglass.com/api/pro/v1/futures/longShort_chart?symbol=BTC&interval=1"
        params = {}
        headers = {
        'coinglassSecret': '00736ebc1bb04a6fbfe5cd9668bd5555',
        'Cache-Control': 'no-cache'
        }
        response = requests.get(url, headers=headers, data = params)
        list_of_dicts = response.json()
        output = "幣安多："+ str(list_of_dicts["data"]["longRateList"][0]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][0])+"%\n歐易多：" + str(list_of_dicts["data"]["longRateList"][1]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][1])+"%\nBitget多："+ str(list_of_dicts["data"]["longRateList"][3]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][3])+"%"
        update.message.reply_text(output)
    elif command == "12h":
        print(command)
        url = "https://open-api.coinglass.com/api/pro/v1/futures/longShort_chart?symbol=BTC&interval=4"
        params = {}
        headers = {
        'coinglassSecret': '00736ebc1bb04a6fbfe5cd9668bd5555',
        'Cache-Control': 'no-cache'
        }
        response = requests.get(url, headers=headers, data = params)
        list_of_dicts = response.json()
        output = "幣安多："+ str(list_of_dicts["data"]["longRateList"][0]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][0])+"%\n歐易多：" + str(list_of_dicts["data"]["longRateList"][1]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][1])+"%\nBitget多："+ str(list_of_dicts["data"]["longRateList"][3]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][3])+"%"
        update.message.reply_text(output)

    elif command == "24h":
        print(command)
        url = "https://open-api.coinglass.com/api/pro/v1/futures/longShort_chart?symbol=BTC&interval=5"
        params = {}
        headers = {
        'coinglassSecret': '00736ebc1bb04a6fbfe5cd9668bd5555',
        'Cache-Control': 'no-cache'
        }
        response = requests.get(url, headers=headers, data = params)
        list_of_dicts = response.json()
        output = "幣安多："+ str(list_of_dicts["data"]["longRateList"][0]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][0])+"%\n歐易多：" + str(list_of_dicts["data"]["longRateList"][1]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][1])+"%\nBitget多："+ str(list_of_dicts["data"]["longRateList"][3]) +"%空："+str(list_of_dicts["data"]["shortsRateList"][3])+"%"
        update.message.reply_text(output)

def main():
    """Start the bot."""
    # Create the Updater and pass it your bot's token.
    # Make sure to set use_context=True to use the new context based callbacks
    # Post version 12 this will no longer be necessary
    api = "5434892407:AAFUQDW8uqA955kIInACe4EwZRkvPUAYbJs"
    updater = Updater(api, use_context=True)

    # Get the dispatcher to register handlers
    dp = updater.dispatcher

    # on different commands - answer in Telegram
    dp.add_handler(CommandHandler("start", start))

    # on noncommand i.e message - echo the message on Telegram
    dp.add_handler(MessageHandler(Filters.text, getratio))

    # log all errors
    dp.add_error_handler(error)

    # Start the Bot
    updater.start_polling()
    # Run the bot until you press Ctrl-C or the process receives SIGINT,
    # SIGTERM or SIGABRT. This should be used most of the time, since
    # start_polling() is non-blocking and will stop the bot gracefully.
    updater.idle()


if __name__ == "__main__":
    main()

