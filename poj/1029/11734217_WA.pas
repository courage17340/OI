var
  b,c,v:array[1..1000] of longint;
  n,k,i,j,p:longint;
  ch:char;
begin
  readln(n,k);
  for i:=1 to 1000 do v[i]:=-maxlongint;
  for i:=1 to k do
    begin
      read(p);
      for j:=1 to p do read(b[j]);
      for j:=1 to p do read(c[j]);
      readln;
      read(ch);
      if ch='=' then
        begin
          for j:=1 to p do v[b[j]]:=0;
          for j:=1 to p do v[c[j]]:=0;
        end;
      if ch='<' then
        begin
          for j:=1 to p do if v[b[j]]<>0 then v[b[j]]:=-i;
          for j:=1 to p do if v[c[j]]<>0 then v[c[j]]:=i;
          for j:=1 to n do if (v[j]<>0)and(v[j]<>-i)and(v[j]<>i) then v[j]:=0;
        end;
      if ch='>' then
        begin
          for j:=1 to p do if v[b[j]]<>0 then v[b[j]]:=i;
          for j:=1 to p do if v[c[j]]<>0 then v[c[j]]:=-i;
          for j:=1 to n do if (v[j]<>0)and(v[j]<>-i)and(v[j]<>i) then v[j]:=0;
        end;
    end;
  j:=0;p:=0;
  for i:=1 to n do
    if v[i]<>0 then
      begin
        j:=i;
        inc(p);
      end;
  if p=1 then writeln(j) else writeln(0);
end.