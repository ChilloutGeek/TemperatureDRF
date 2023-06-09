from django.shortcuts import render
from rest_framework import serializers
from rest_framework.viewsets import ViewSet
from rest_framework.response import Response 
# Create your views here.

from .serializers import TemperatureSerializer
from .models import Temperature

class TemperatureView(ViewSet):
    
    def templist(self, request):
        data = Temperature.objects.all()
        serializer = TemperatureSerializer(data, many=True)

        return Response(serializer.data, status=200)
    
    #sensor sends POST data to DRF
    def tempread(self, request):
        serializer = TemperatureSerializer(data=request.data)
        serializer.is_valid(raise_exception=True)
        serializer.save()

        return Response(serializer.data, status=201)


