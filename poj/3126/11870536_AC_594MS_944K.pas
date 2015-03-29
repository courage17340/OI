var
  a:array[2..10000] of boolean;
  f:array[1000..9999] of longint;
  v:array[1000..9999] of boolean;
  b:array[1..8000] of longint;
  n,i,j,k,x,y,p:longint;
function yes(x,y:longint):boolean;
var
  s,t:string;
  i,p:longint;
begin
  if v[x] then exit(false);
  str(x,s);
  str(y,t);
  p:=0;
  for i:=1 to 4 do inc(p,ord(s[i]<>t[i]));
  exit(p=1);
end;
begin
  fillchar(a,sizeof(a),1);
  i:=2;
  while i<100 do
    begin
      while not a[i] do inc(i);
      for j:=2 to 10000 div i do a[i*j]:=false;
      inc(i);
    end;
  readln(n);
  for p:=1 to n do
    begin
      readln(x,y);
      if x=y then
        begin
          writeln(0);
          continue;
        end;
      fillchar(f,sizeof(f),0);
      fillchar(v,sizeof(v),0);
      i:=1;
      j:=1;
      b[1]:=x;
      while i<j+1 do
        begin
          if f[y]>0 then break;
          for k:=1000 to 9999 do
            if a[k] and yes(k,b[i]) then
              begin
                v[k]:=true;
                inc(j);
                f[k]:=f[b[i]]+1;
                b[j]:=k;
              end;
          inc(i);
        end;
      if f[y]>0 then writeln(f[y]) else writeln('Impossible');
    end;
end.