var
  a,b:array['A'..'Z'] of longint;
  n,i,j,p:longint;
  s:ansistring;
  t:boolean;
function min(a,b:longint):longint;
begin
  min:=a;if a>b then min:=b;
end;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
    begin
      readln(s);
      while true do
        begin
          p:=0;
          while s[1] in ['0'..'9'] do
            begin
              p:=p*10+ord(s[1])-48;
              delete(s,1,1);
            end;
          if p=0 then p:=1;
          inc(a[s[1]],p);
          delete(s,1,1);
          if s[1]='=' then begin delete(s,1,1);break;end;
          delete(s,1,1);
        end;
      while length(s)>0 do
        begin
          p:=0;
          while s[1] in ['0'..'9'] do
            begin
              p:=p*10+ord(s[1])-48;
              delete(s,1,1);
            end;
          if p=0 then p:=1;
          inc(b[s[1]],p);
          delete(s,1,2);
        end;
    end;
  for i:=1 to 26 do
    begin
      p:=min(a[chr(i+64)],b[chr(i+64)]);
      dec(a[chr(i+64)],p);
      dec(b[chr(i+64)],p);
    end;
  p:=maxlongint;
  for i:=1 to 26 do
    begin
      if a[chr(i+64)]>0 then p:=min(p,a[chr(i+64)]);
      if b[chr(i+64)]>0 then p:=min(p,b[chr(i+64)]);
    end;
  for i:=2 to p do
    begin
      repeat
        t:=true;
        for j:=1 to 26 do
          begin
            if a[chr(j+64)] mod i>0 then t:=false;
            if b[chr(j+64)] mod i>0 then t:=false;
          end;
        if t then for j:=1 to 26 do
          begin
            a[chr(j+64)]:=a[chr(j+64)] div i;
            b[chr(j+64)]:=b[chr(j+64)] div i;
          end;
        until not t;
    end;
  p:=1;
  while a[chr(p+64)]=0 do inc(p);
  if a[chr(p+64)]>1 then write(a[chr(p+64)]); 
  write(chr(p+64));
  for i:=p+1 to 26 do
    if a[chr(i+64)]>0 then
      begin write('+');if a[chr(i+64)]>1 then write(a[chr(i+64)]);write(chr(i+64));end;
  write('=');
  p:=1;
  while b[chr(p+64)]=0 do inc(p);
  if b[chr(p+64)]>1 then write(b[chr(p+64)]);
  write(chr(p+64));
  for i:=p+1 to 26 do
    if b[chr(i+64)]>0 then
      begin write('+');if b[chr(i+64)]>1 then write(b[chr(i+64)]);write(chr(i+64));end;
  writeln;
end.