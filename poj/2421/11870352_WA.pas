var
  a:array[1..100,1..100] of longint;
  n,m,i,j,k,ans,p,q,x,y,d:longint;
  v:array[1..100] of boolean;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  readln(m);
  fillchar(v,sizeof(v),0);
  for i:=1 to m do
    begin
      readln(x,y);
      v[x]:=true;
      v[y]:=true;
    end;
  x:=0;
  ans:=0;
  for i:=1 to n do inc(x,ord(v[i]));
  if x=0 then
    begin
      d:=maxlongint;
      for i:=1 to n-1 do
        for j:=i+1 to n do
          if a[i,j]<d then
            begin
              d:=a[i,j];
              p:=i;
              q:=j;
            end;
      ans:=d;
      v[p]:=true;
      v[q]:=true;
      x:=2;
    end;
  for i:=x+1 to n do
    begin
      d:=maxlongint;
      for j:=1 to n do if v[j] then
        for k:=1 to n do if not v[k] then
          if a[j,k]<d then
            begin
              d:=a[j,k];
              p:=k;
            end;
      inc(ans,d);
      v[p]:=true;
    end;
  writeln(ans);
end.