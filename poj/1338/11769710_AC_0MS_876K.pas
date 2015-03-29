var
  a,b,c,d:array[1..1600] of longint;
  i,j,k,n,i1,j1,k1:longint;
begin
  a[1]:=1;
  b[1]:=2;
  c[1]:=3;
  d[1]:=5;
  i:=1;j:=1;k:=1;
  i1:=1;j1:=1;k1:=1;
  for n:=2 to 1500 do
    begin
      if b[i]=c[j] then inc(i);
      if b[i]=d[k] then inc(i);
      if c[j]=d[k] then inc(j);
      if (b[i]<c[j])and(b[i]<d[k]) then
        begin
          inc(i1);b[i1]:=b[i]*2;
          inc(j1);c[j1]:=b[i]*3;
          inc(k1);d[k1]:=b[i]*5;
          a[n]:=b[i];
          inc(i);
          continue;
        end;
      if (c[j]<b[i])and(c[j]<d[k]) then
        begin
          inc(i1);b[i1]:=c[j]*2;
          inc(j1);c[j1]:=c[j]*3;
          inc(k1);d[k1]:=c[j]*5;
          a[n]:=c[j];
          inc(j);
          continue;
        end;
      if (d[k]<b[i])and(d[k]<c[j]) then
        begin
          inc(i1);b[i1]:=d[k]*2;
          inc(j1);c[j1]:=d[k]*3;
          inc(k1);d[k1]:=d[k]*5;
          a[n]:=d[k];
          inc(k);
          continue;
        end;
    end;
  while true do
    begin
      readln(n);
      if n=0 then break;
      writeln(a[n]);
    end;
end.