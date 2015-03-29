var
  a,f1,f2:array[1..1000000] of longint;
  n,i,j,k,k1,k2:longint;
begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  k1:=1;
  for i:=2 to k do if a[i]<=a[k1] then k1:=i;
  k2:=1;
  for i:=2 to k do if a[i]>=a[k2] then k2:=i;
  f1[k]:=a[k1];
  f2[k]:=a[k2];
  for i:=k+1 to n do
    begin
      if k1<i-k+1 then
        begin
          k1:=i-k+1;
          for j:=k1+1 to i do
            if a[j]<=a[k1] then k1:=j;
        end;
      if k2<i-k+1 then
        begin
          k2:=i-k+1;
          for j:=k2+1 to i do
            if a[j]>=a[k2] then k2:=j;
        end;
      if a[i]<a[k1] then k1:=i;
      if a[i]>a[k2] then k2:=i;
      f1[i]:=a[k1];
      f2[i]:=a[k2];
    end;
  for i:=k to n-1 do write(f1[i],' ');
  writeln(f1[n]);
  for i:=k to n-1 do write(f2[i],' ');
  writeln(f2[n]);
end.