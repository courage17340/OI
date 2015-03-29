var n,i,d,j,k,ls:longint;
    s,e:string;
    b:array[0..100] of longint;
    ch:char;
begin
 read(n);
 b[0]:=0;
 while b[0]=0 do
 begin
    s:='1';
    for i:=1 to n-1 do
    begin
      if b[i]=1 then s:=s+'+';
      if b[i]=2 then s:=s+'-';
      str(i+1,e);
      s:=s+e;
    end;
    s:=s+'+';
    ls:=length(s);
    d:=0;
    k:=0;
    ch:='+';
    for i:=1 to ls do
      if s[i] in ['0'..'9'] then
        k:=k*10+ord(s[i])-48
      else
      begin
        if ch='+' then d:=d+k;
        if ch='-' then d:=d-k;
        k:=0;
        ch:=s[i];
      end;
    if d=0 then
    begin
      for i:=1 to n-1 do
      begin
        write(i);
        if b[i]=1 then write('+');
        if b[i]=2 then write('-');
        if b[i]=0 then write(' ');
      end;
      writeln(n);
    end;
    j:=n-1;
    while b[j]=2 do
    begin
      b[j]:=0;
      dec(j);
    end;
    inc(b[j]);
 end;
end.