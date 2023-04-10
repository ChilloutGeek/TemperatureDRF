from .models import Temperature
from rest_framework import serializers
from rest_framework.serializers import ModelSerializer

class TemperatureSerializer(ModelSerializer):
    class Meta:
        model = Temperature
        fields = '__all__'