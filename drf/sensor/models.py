from django.db import models

# Create your models here.
class Temperature(models.Model):
    temp = models.FloatField(null=True)