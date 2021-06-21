import tweepy
from airflow.hooks.filesystem import FSHook
from airflow.operators.python import PythonOperator
from airflow.sensors.filesystem import FileSensor
from textblob import TextBlob
import re
from airflow import DAG
from datetime import datetime
import os

querry = "nasa"
quantity = 50

default_args = {
    'owner': 'airflow',
    'depends_on_past': False,
    'start_date': datetime(2021, 6, 19),
    'retries': 0
}

dag = DAG(dag_id='Twitter', default_args=default_args, catchup=False, schedule_interval='@once')
results = [0, 0, 0]


def getdata(**context):
    ck = ""
    cs = ""
    atk = ""
    ats = ""

    auth = tweepy.OAuthHandler(ck, cs)
    auth.set_access_token(atk, ats)
    api = tweepy.API(auth)

    tweets = tweepy.Cursor(api.search, q=querry, tweet_mode="extended").items(quantity)

    hook = FSHook('tweets')
    path = os.path.join(hook.get_path(), 'tweets.txt')
    with open(path, 'w+') as f:
        for tweet in tweets:
            f.write(cleantext(tweet.full_text) + "\n")

        f.close()


def analyzedata(**context):
    positive = 0
    neutral = 0
    negative = 0

    hook = FSHook('tweets')
    path = os.path.join(hook.get_path(), 'tweets.txt')
    with open(path, 'r+') as f:
        lines = f.readlines()

        for tweet in lines:
            analysis = TextBlob(tweet)
            print(str(analysis.polarity) + "\n")
            if analysis.polarity > 0.0:
                positive += 1
            elif analysis.polarity == 0.0:
                neutral += 1
            elif analysis.polarity < 0.0:
                negative += 1

        f.close()

    results[0] += positive
    results[1] += neutral
    results[2] += negative


def cleantext(text):
    text = re.sub(r'@[A-Za-z0-9]+', '', text)
    text = re.sub(r':', '', text)
    text = re.sub(r'#', '', text)
    text = re.sub(r'RT[\s]+', '', text)
    text = re.sub(r'https?://\S+', '', text)
    return text


def printresults():
    print("> Item pesquisado: " + querry)
    print("> Quantidade de tweets pesquisados: " + str(quantity))
    print(f"> Positivo: {round((int(results[0]) * 100) / quantity, 2)}%")
    print(f"> Neutro: {round((int(results[1]) * 100) / quantity, 2)}%")
    print(f"> Negativo: {round((int(results[2]) * 100) / quantity, 2)}%")


get_data_operator = FileSensor(
    task_id='get_data',
    filepath='tweets.txt',
    fs_conn_id='tweets',
    poke_interval=10,
    dag=dag)

analyze_data_operator = FileSensor(
    task_id='analyze_data',
    filepath='tweets.txt',
    fs_conn_id='tweets',
    poke_interval=10,
    dag=dag)

print_results_operator = PythonOperator(
    task_id='print_results',
    python_callable=printresults,
    dag=dag)

get_data_operator >> analyze_data_operator >> print_results_operator
